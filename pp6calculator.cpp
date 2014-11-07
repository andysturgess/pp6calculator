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

int main(){

  double a(0), b(0), res(0), res2(0), c(0), d(0);
  std::pair<std::string,std::string> twox;
  char op('\0');
  
  while(true){
    std::cout << "What would you like to do? (*,/,-,+,i,x).. (q = quit) "<< std::endl;
    std:: cin >> op;
    if (!std::cin){
      std::cerr<<" [ERR] Please enter a valid operation"<< std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
     continue;
    }
    
    if(op == 'q') break;
    if(op == 'x') std::cout << "The form of a quadratic is ax^2 + bx + c" <<std::endl;
    
    
    if(op == 'i') std::cout << "Please enter x of point 1" << std::endl;
    else if(op == 'x') std::cout << "Please enter 'a'" << std::endl;
    else std::cout << "Please enter your first number" << std::endl;
    
    
    std::cin >> a;
    if(!std::cin){
      std::cerr<<"[ERR] Please enter a valid number" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }
   
    if(op == 'i')  std::cout << "Please enter y of point 1" << std::endl;
    else if(op == 'x') std::cout << "Please enter 'b'" << std::endl;
    else std::cout << "Please enter your second number" << std::endl;
    
    std::cin >> b;
    if(!std::cin){
      std::cerr<<"[ERR] Please enter a valid number" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }
    
    if((op =='i') or (op == 'x')){
     if(op =='i') std::cout << "Please enter your x of point 2" << std::endl;
     else std::cout << "Please enter 'c'" << std::endl;
     std::cin >> c;
     if(!std::cin){
       std::cerr<<"[ERR] Please enter a valid number" << std::endl;
       std::cin.clear();
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
       continue;
     }
    }
    
    if(op == 'i'){
      std::cout << "Please enter y of point 2" << std::endl;
      std::cin >> d;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }
    }
    
    
    
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
    else
      {
	std::cerr<<"[ERR] we need a valid operation"<<std::endl;
	continue;
      }

    
   
    if(op == 'i'){
      std::cout << "intercept of x for a line connecting coords ("<< a << ","<< b
		<< ") and (" << c << ","<< d
		<< ") is " << res << std::endl;
      if(isnan(res)){
	std::cout << "You have a vertical line," 
		  << " your x intercept must be "
		  << a << std::endl;
      }
    }
    else if (op == 'x'){
      std::cout << "The two solutions for this quadratic equation are "
		<< twox.first << " and " << twox.second << std::endl;
    }
    else{
      std::cout << "the result of the operation '" << op
	       << "' for numbers " << a << " and " << b
		<< " is " << res << std::endl;
    }
    
  }
  
  std::cout << "Hope you enjoyed using the calculator" << std::endl;
  return 0;
}
