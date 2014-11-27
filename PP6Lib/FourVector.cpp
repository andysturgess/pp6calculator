//FourVector.cpp: Implementation of FourVector

#include "FourVector.hpp"
#include <cmath>
#include <iostream>

FourVector::FourVector(const double x_, const double y_,
				 const double z_, const double t_)
  : x(x_), y(y_), z(z_), t(t_)
{}

double FourVector::getX() {
  return x;
}
double FourVector::getY() {
  return y;
}
double FourVector::getZ() {
  return z;
}
double FourVector::getT() {
  return t;
}

void FourVector::setX(double value) {
  x = value;
}
void FourVector::setY(double value) {
  y = value;
}
void FourVector::setZ(double value) {
  z = value;
}
void FourVector::setT(double value) {
  t = value;
}


FourVector operator+(const FourVector& lhs, const FourVector& rhs){
  FourVector temp(lhs);
  temp += rhs;
  return temp;
}

FourVector operator-(const FourVector& lhs, const FourVector& rhs){
  FourVector temp(lhs);
  temp -= rhs;
  return temp;
}

FourVector operator*(const FourVector& lhs, const FourVector& rhs){
  FourVector temp(lhs);
  temp *= rhs;
  return temp;
}

FourVector operator/(const FourVector& lhs, const FourVector& rhs){
  FourVector temp(lhs);
  temp /= rhs;
  return temp;
}

FourVector operator==(const FourVector& lhs, const FourVector& rhs){
  FourVector temp(lhs);
  temp == rhs;
  return temp;
}

double FourVector::interval() const{
  double s = t*t -x*x -y*y -z*z;
  return s;
}

void FourVector::boost_z(double v){

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

FourVector::CausalType FourVector::getCausalType(FourVector q){
double res = q.interval();
  if(res > 0){
    return TIMEL;
  }
  else if(res < 0){
    return SPACEL;
  }
  else{
    return LIGHTL;
  }
}
