#include "PP6Math.hpp"

// Standard Library

#include <iostream>
#include <cmath>
#include <limits>
#include <utility>
#include <complex>
#include <vector>
#include <cstdlib>

//---------------------------------------------------------------------
// Function Definitions

double add(double a,double b){
  return a + b;
}

double subtract(double a, double b){
  return a - b;
}
double multiply(double a,double b){
  return a * b;
}
double divide(double a, double b){
  return a / b;
}
double intercept(double a, double b, double c, double d){
  double gradient = (d-b)/(c-a);
  double x_intercept = b - gradient*a;
  return x_intercept;
}

std::pair<std::complex<double>,std::complex<double> > quadratic(std::complex<double> m,std::complex<double> n, std::complex<double> o, bool& pos, bool& neg){
  std::complex<double> discriminant = n * n - 4.0*m*o;
  if (std::real(discriminant) >= 0.){ 
    pos = true;
  }
  else{
    neg = true;
  }
  std::pair<std::complex<double>,std::complex<double> > solutions;
  std::complex<double> x1 = (-n + std::sqrt(discriminant))/(2.*m);
  std::complex<double> x2 = (-n - std::sqrt(discriminant))/(2.*m);
  solutions.first = x1;
  solutions.second = x2; 
  return solutions;
}

double vectorlength3(double a, double b, double c){
  double length_3 =std::sqrt( a*a + b*b +  c*c);
  return length_3;
}

double vectorlength4(double a, double b, double c, double d){
  double length_4 = d*d - a*a - b*b -c*c ;
  return length_4;
}

double invmass(double a, double b, double c, double d, double theta){
  double ConvertDegtoRad = theta * (3.14159/180);
  double squared_terms = a*a + c*c -b*b - d*d;
  double cross_terms = 2*a*c - 2*b*d*ConvertDegtoRad;
  double inv_mass_sq = squared_terms + cross_terms;
  double inv_mass = sqrt(inv_mass_sq);
  return inv_mass;
}

// - Day two

double inputvalue(){
  double value(0);
  std::cin >> value;
  while(!std::cin){
    std::cout << "[ERR]. Please enter a valid number!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> value;
  }
  return value;
}

void swap(double& a, double&b){
  a = a + b;
  b = a - b;
  a = a - b;
}

void Bubble(double array[]){
  int i,j;
  for(i = 0; i < 5; i++){
    for(j = 0; j < 4 - i; j++){
      if(array[j] < array[j+1]){
	swap(array[j],array[j+1]);
      }
    }
  }

}

void SPECTRUM(){
  double p_x[100];
  double p_y[100];
  double p_z[100];
  double M[100];
  double E[100];
  double total_E = 0;
  double ximinmu[100];
  double stddev = 0;
  
  for(int i = 0; i < 100; i++){
    p_x[i] = rand()%100;
    p_y[i] = rand()%100;
    p_z[i] = rand()%100;
    M[i] = rand()%100;
    E[i] = std::sqrt(p_x[i]*p_x[i] + p_y[i]*p_y[i] + p_z[i]*p_z[i] + M[i]*M[i]);
  }
			  
  for(int i = 0; i < 100; i++){
    std::cout<< " E for particle " << i << " is " << E[i] << " GeV" <<std::endl;
    total_E = total_E + E[i];
   
  }

  for(int i = 0; i < 100; i++){
    ximinmu[i] = (E[i] - total_E/100.)*(E[i] - total_E/100.);
    stddev = stddev + ximinmu[i];
  }
  
  std::cout << "The average energy is (" << total_E/100. << "+/-" 
	    << std::sqrt(stddev/100.) << ") GeV, for 100 random particles" << std::endl;
}

// - Day Three

void boostalongz(double x, double y, double& z, double& t, double v){
  double gamma = 1/(std::sqrt(1-v*v));
  x = x;
  y = y;
  z = gamma*(z - v*t);
  t = gamma*(t - v*z);
}

void boostz(FourVector q, double v){
  double gamma = 1/(std::sqrt(1-v*v));
  q.x = q.x;
  q.y = q.y;
  q.z = gamma*((q.z) - v*(q.t));
  q.t = gamma*((q.t) - v*(q.z));
 
  std::cout << "the results of the boost" << std::endl;
  std::cout << " x component = " << q.x << std::endl;
  std::cout << " y component = " << q.y << std::endl;
  std::cout << " z component = " << q.z << std::endl;
  std::cout << " t component = " << q.t << std::endl;	  
}

double invint(FourVector q){
  double interval =  (q.t)*(q.t)-(q.x)*(q.x) -  (q.y)*(q.y) - (q.z)*(q.z); 
  return interval;
}



void fillFourVector(FourVector *q, double &x, double &y, double &z, double &t){
  if(q){
    q->x=x;
    q->y=y;
    q->z=z;
    q->t=t;
  }
}

FourVector* createFourVector(){
  return new FourVector;
}

void destroyFourVector(FourVector *&q){
  if(q){
    delete q;
    q = 0;
  }
}

void evalboostz(FourVector *q , double v){
  if(q){
    double gamma = 1/(std::sqrt(1-v*v));
    q->x = q->x;
    q->y = q->y;
    q->z = gamma*((q->z) - v*(q->t));
    q->t = gamma*((q->t) - v*(q->z));
 
    std::cout << "the results of the boost" << std::endl;
    std::cout << " x component = " << q->x << std::endl;
    std::cout << " y component = " << q->y << std::endl;
    std::cout << " z component = " << q->z << std::endl;
    std::cout << " t component = " << q->t << std::endl;
  }	
}

void opinterval(FourVector *q){
  if(q){
    double iv = ((q->t)*(q->t) -(q->x)*(q->x) - (q->y)*(q->y) - (q->z)*(q->z));
    std::cout << "The invariant interval is " << iv << std::endl;
  }	
}

InvariantSign getInvariantSign(FourVector *q){
  if(!q){
    return UNDEFINED;
  }

  double iv = ((q->t)*(q->t) -(q->x)*(q->x) - (q->y)*(q->y) - (q->z)*(q->z));
  if(iv > 0){
    return TIMELIKE;
  }
  else if(iv < 0){
    return SPACELIKE;
  }
  else{
    return LIGHTLIKE;
  }
}

FourVectorclass::FourVectorclass(const double x_, const double y_,
				 const double z_, const double t_)
  : x(x_), y(y_), z(z_), t(t_)
{}

double FourVectorclass::getx() {
  return x;
}

double FourVectorclass::gety() {
  return y;
}

double FourVectorclass::getz() {
  return z;
}

double FourVectorclass::gett() {
  return t;
}

void FourVectorclass::setx(double value) {
  x = value;
}

void FourVectorclass::sety(double value) {
  y = value;
}

void FourVectorclass::setz(double value) {
  z = value;
}

void FourVectorclass::sett(double value) {
  t = value;
}


FourVectorclass operator+(const FourVectorclass& lhs, const FourVectorclass& rhs)
{
  FourVectorclass temp(lhs);
  temp += rhs;
  return temp;
}

FourVectorclass operator-(const FourVectorclass& lhs, const FourVectorclass& rhs)
{
  FourVectorclass temp(lhs);
  temp -= rhs;
  return temp;
}


double FourVectorclass::interval() const{
  double s = t*t -x*x -y*y -z*z;
  return s;

}

void FourVectorclass::boost_z(double v){
 double gamma = 1/(std::sqrt(1-v*v));
  x = x;
  y = y;
  z = gamma*(z - v*t);
  t = gamma*(t - v*z);

  std::cout << "the results of the boost" << std::endl;
  std::cout << " x component = " << x << std::endl;
  std::cout << " y component = " << y << std::endl;
  std::cout << " z component = " << z << std::endl;
  std::cout << " t component = " << t << std::endl;

}
