#include <iostream>
#include <cmath>
#include <math.h>
#include <limits>
#include <vector>
#include <utility>
#include <sstream>

//Now we define the functions!

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
  double dx = c-a;
  double cint = b - gradient*a;
  if (gradient == 0.){
    return 0;
  }
  else if (!gradient == 0){
    return -cint/gradient;
  }
  else if (dx == 0){
    return -cint/gradient;
  }
}

// quadratic function, need imaginary numbers. 
// pair of strings seems to be natural solution!

std::pair<std::string,std::string> quadratic(double a, double b, double c){                          
  double quotient = (b*b - 4*a*c);
  std::string solve1; 
  std::string solve2;

  if(quotient >= 0.){
    double discr1 = (-b + sqrt(quotient))/(2*a) ;
    double discr2 = (-b - sqrt(quotient))/(2*a) ;
    std::ostringstream strs1;
    std::ostringstream strs2;
    strs1 << discr1;
    strs2 << discr2;
    std::string str1 = strs1.str();
    std::string str2 = strs2.str();
    solve1 = str1;
    solve2 = str2;
  }
  else{
    double discr1 = sqrt(fabs(quotient))/(2*a);
    double discr2 = (-b/(2*a));
    std::ostringstream strs1;
    std::ostringstream strs2;
    strs1 << discr1;
    strs2 << discr2;
    std::string str1 = strs1.str() + "i";
    std::string str2 = strs2.str() + "+" + str1;
    std::string str3 = strs2.str() + "-" + str1;
    solve1 = str2;
    solve2 = str3; 
  }
  std::pair<std::string,std::string> solve;
  solve.first = solve1;
  solve.second = solve2;
  return solve;
}

// use a pair again here, i.e save results of both to a single object
// can then call either dependent on if picking three or four vector!

std::pair<double,double> vectorlength(double a, double b, double c, double d){
  double length_3 = sqrt(a*a + b*b +c*c);
  double length_4 = d*d - a*a -b*b - c*c;
  std::pair<double,double> length;
  length.first = length_3;
  length.second = length_4;
  return length;
}

double invmass(double a, double b, double c, double d, double theta){
  double angle = theta * (3.14159/180);
  double sqterm = a*a + c*c -b*b - d*d;
  double crossterm = 2*a*c - 2*b*d*angle;
  double inv2 = sqterm + crossterm;
  double inv = sqrt(inv2);
  return inv;
}

// Start of the main program!!

int main(){

  double a(0), b(0), res(0), res2(0), c(0), d(0), check(0), theta(0);
  std::pair<std::string,std::string> twox;
  std::pair<double,double> vlength;
  char op('\0');
  
  while(true){
    std::cout << "What would you like to do? (*,/,-,+,i,x,l).. (q = quit) "<< std::endl;
    std::cout << "*  = multiplication." << std::endl;
    std::cout << "/  = division." << std::endl;
    std::cout << "-  = subtraction." << std::endl;
    std::cout << "*  = addition" << std::endl;
    std::cout << "i  = x intercept." << std::endl;
    std::cout << "x  = solve a quadratic." << std::endl;
    std::cout << "l  = length of 3 or 4 vector." << std::endl;
    std::cout << "m  = invariant mass of two particles " << std::endl;

   
    std:: cin >> op;
    if (!std::cin){
      std::cerr<<" [ERR] Please enter a valid operation"<< std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }
    
    // asks you what you'd like to do!
    
    if(op == 'q') break;
    if(op == 'x') std::cout << "The form of a quadratic is ax^2 + bx + c" <<std::endl;
    
    if(op == 'l'){
      std::cout << "Determine the length of a 3 or 4 vector?" <<std::endl;
      std::cout << "0. 3 Vector" << std::endl;
      std::cout << "1. 4 Vector" << std::endl;
      std::cin >> check;
      if(fabs(check) > 1){
	std::cout << " \n  Please choose again! \n" << std::endl;
	continue;
      }
    }
    
    // some statements to see on screen, dependent on the function being used!
    // Note: vector length has two options within the function!
    
    if(op == 'i') std::cout << "Please enter x of point 1" << std::endl;
    else if(op == 'x') std::cout << "Please enter 'a'" << std::endl;
    else if(op == 'l') std::cout << "Please enter 'x'" << std::endl;
    else if(op == 'm') std::cout << "Plese enter the energy of particle 1(GeV)" << std::endl;
    else std::cout << "Please enter your first number" << std::endl;
    
    
    std::cin >> a;
    if(!std::cin){
      std::cerr<<"[ERR] Please enter a valid number" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }

    // every function needs at least two inputs - this is the first.
   
    if(op == 'i')  std::cout << "Please enter y of point 1" << std::endl;
    else if(op == 'x') std::cout << "Please enter 'b'" << std::endl;
    else if(op == 'l') std::cout << "Please enter 'y'" << std::endl;
    else if(op == 'm') std::cout << "Please enter the momentum of particle 1 (GeV)" << std::endl;
    else std::cout << "Please enter your second number" << std::endl;
    
    std::cin >> b;
    if(!std::cin){
      std::cerr<<"[ERR] Please enter a valid number" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }
    
    // every function needs at least two inputs - this is the second.

    if (b > a){
      std::cout << "Momentum is greater than energy? not possible!" << std::endl;
      continue;
    }

    // stops invalid inv mass calculation
    
    if(op =='i' || op == 'x' || op ==  'l' || op == 'm'){
      if(op =='i') std::cout << "Please enter your x of point 2" << std::endl;
      else if (op == 'l') std::cout << "Please enter 'z'" << std::endl;
      else if (op == 'm') std::cout << "Please enter the energy of particle 2(GeV)" << std::endl;
      else std::cout << "Please enter 'c'" << std::endl;
      std::cin >> c;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }
    }
    
    //only intercept, quadratic, vector length and invariant mass need three inputs
    
    if(op == 'i'|| check == 1 || op == 'm' ){
      if(op =='i') std::cout << "Please enter y of point 2" << std::endl;
      else if (op == 'l') std::cout << "Please enter 't'" << std::endl;
      else if (op == 'm') std::cout << "Please enter the momentum  of particle 2(GeV)" << std::endl;
      std::cin >> d;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }
    }

    //only intercept, vector length and invariant mass need four inputs
    
    if (d > c){
      std::cout << "Momentum is greater than energy? not possible!" << std::endl;
      continue;
    }
    
    // stops invalid inv mass calculation

    if(op == 'm'){
      std::cout << "What is the angle of collision between the two particles? (180 deg is head on!)"
		<< std::endl;
      std::cin >> theta;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }
      if(theta > 180){
	std::cout << " Pick a more sensible angle!" << std::endl;
	continue;
      }
    }

    //only invariant mass needs five inputs
    
    if(op == '+'){
      res = add(a,b);
    }
    else if(op == '-'){
      res = subtract(a,b);
    }
    else if (op == '*'){
      res = multiply(a,b);
    }
    else if (op == '/'){
      if(fabs(b) > 0){
	res = divide(a,b);
      }
      if(fabs(b) == 0){
	std::cerr<<"[ERR] Can't divide by zero!" << std::endl;
	continue;
      }
    }
    else if(op == 'i'){
      res = intercept(a,b,c,d);
    }
    else if(op == 'x'){
      twox = quadratic(a,b,c);
    }
    else if(op == 'l'){
      vlength = vectorlength(a,b,c,d);
    }
    else if(op == 'm'){
      res = invmass(a,b,c,d,theta);
    }
    
    else{
      std::cerr<<"[ERR] we need a valid operation"<<std::endl;
      continue;
    }
    
    // the if and else statements; these assign results dependent on the function!
 
    if(op == 'i'){
      std::cout << "intercept of x for a line connecting coords ("
		<< a << ","<< b
		<< ") and (" << c << ","<< d
		<< ") is " << res << "\n" << std::endl;
      if(isnan(res)){
	std::cout << "You have a vertical line," 
		  << " your x intercept must be "
		  << a << "\n" <<std::endl;
      }
    }
    else if (op == 'x'){
      std::cout << "The two solutions for this quadratic equation are "
		<< twox.first << " and " << twox.second << "\n" << std::endl;
    }
    else if (op == 'l'){
      if(check == 0){
	std::cout << "The length of this three vector is " 
		  << vlength.first << "\n" <<std::endl;
      }
      else{
	std::cout << "The length of this four vector is " 
		  << vlength.second << std::endl;
	if(vlength.second == 0) std::cout << "You have a NULL vector!" << std::endl;
	else if(vlength.second > 0) std::cout << "You have a TIMELIKE vector!" << std::endl;
	else std::cout << "You have a SPACELIKE vector! \n" << std::endl;
      }
    }
    else if(op == 'm'){
      std::cout << "The invariant mass of the two particle system is "
		<< res << " GeV \n" << std::endl;
    }

    else{
      std::cout << "the result of the operation '" << op
		<< "' for numbers " << a << " and " << b
		<< " is " << res << "\n" <<std::endl;
    } 
  }

  // outputting the results to screen; each function has a different output.
  
  std::cout << "Please use me again sometime in the future?" << std::endl;
  return 0;
}
