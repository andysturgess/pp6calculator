// DAY1_MENU.cpp: defining the menu functions;

#include "DAY1_MENU.hpp"
#include <iostream>
#include <limits>
#include "PP6Math.hpp"

void day1_menu(){
  double res(0), a(0), b(0),c(0),d(0), theta(0);
  std::pair<std::complex<double>,std::complex<double> > ReturnQuadSols;
  char op('\0');

  while(true){
    std::cout << "PP6Calulator - DAY 1 MENU" << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "*  = multiplication." << std::endl;
    std::cout << "/  = division." << std::endl;
    std::cout << "-  = subtraction." << std::endl;
    std::cout << "+  = addition" << std::endl;
    std::cout << "i  = x intercept." << std::endl;
    std::cout << "x  = solve a quadratic." << std::endl;
    std::cout << "t  = length of a 3 vector." << std::endl;
    std::cout << "f  = length of a 4 vector." << std::endl;
    std::cout << "m  = invariant mass of two particles " << std::endl;
    std::cout << "=====================================" << std::endl;

    std::cin >> op;
    if(!std::cin){
      std::cerr << "[ERR] Please enter a valid operation" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }
    
    if(op == 'q') break;
    
    else if((op == '*') || (op == '/') || (op == '+') || (op == '-')){
      std::cout << "Enter your first number" << std::endl;
      a = inputvalue();
      std::cout << "Enter your second number" << std::endl;
      b = inputvalue();
    

      if(op == '*'){
	res = multiply(a,b);
	std::cout << "multiplying " << a
		  << " and " << b << "gives "
		  << res << std::endl;
      }

      if(op == '/'){
	res = divide(a,b);
	std::cout << "dividing " << a
		  << " and " << b << "gives "
		  << res << std::endl;
      }
      
      if(op == '+'){
	res = add(a,b);
	std::cout << "adding " << a
		  << " and " << b << "gives "
		  << res << std::endl;
      }
      
      if(op == '-'){
	res = subtract(a,b);
	std::cout << "adding " << a
		  << " and " << b << "gives "
		  << res << std::endl;
      }
    }

    else if (op == 'i'){
      std::cout <<"Enter x1" << std::endl;
      a = inputvalue();
      std::cout << "Enter y1" << std::endl;
      b = inputvalue();
      std::cout << "Enter x2" << std::endl;
      c = inputvalue();
      std::cout << "Enter y2" << std::endl;
      d = inputvalue();
    
      res = intercept(a,b,c,d);
      std::cout<< " The y intercept of points (" << a << " , " << b
	       << ") and (" << c << " , " << d << ") is" << res
	       << std::endl;
    }

    else if(op == 'x'){
      std::cout << "the standard form of quadratic equation is ax^2 + bx + c)" << std::endl;

    bool pos = false; 
    bool neg = false;

    // The two variables which are used for passing by reference
    // Not really important; just another way of telling us if  
    // we are dealing with imaginary solutions or not.

    std::cout << "Please enter a" << std::endl;
    std::complex<double> m;
    std::cin >> m;
    if(!std::cin){
      std::cerr<<"[ERR] Please enter a valid number" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }
      
    std::cout << "Please enter b" << std::endl;
    std::complex<double> n;
    std::cin >> n;
    if(!std::cin){
      std::cerr<<"[ERR] Please enter a valid number" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }
      
    std::cout << "Please enter c" << std::endl;
    std::complex<double> o;
    std::cin >> o;
    if(!std::cin){
      std::cerr<<"[ERR] Please enter a valid number" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }
      
      
    ReturnQuadSols = quadratic(m,n,o,pos,neg);
    if (pos == true) std::cout << " valid discriminant = non-imaginary solutions"
			       << std::endl;
    if (neg == true) std::cout << " invalid discriminant = imaginary solutions"
			       << std::endl;
    std::cout << " The form of the solution is (real,imaginary)" << std::endl;
    std::cout << " for example, a solution like (-3 + 2i) & (-3 - 2i)" << std::endl;
    std::cout << " Would appear as (-3,2) and (-3,-2)" << std::endl;
    std::cout << " The two solutions for this quadratic equation are "
	      << ReturnQuadSols.first << " and " << ReturnQuadSols.second << "\n" << std::endl;
    }
    
    else if(op == 't'){
      std::cout << "Please enter the magnitude of x" << std::endl;
      a = inputvalue();
      std::cout << "Please enter the magnitude of y" << std::endl;
      b = inputvalue();
      std::cout << "Please enter the magnitude of z" << std::endl;
      c = inputvalue();
      
      res = vectorlength3(a,b,c);
      std::cout << " The length of this three-vector is " << res << std::endl;
    }

    else if(op == 'f'){
      std::cout << "Please enter the magnitude of x" << std::endl;
      a = inputvalue();
      std::cout << "Please enter the magnitude of y" << std::endl;
      b = inputvalue();
      std::cout << "Please enter the magnitude of z" << std::endl;
      c = inputvalue();
      std::cout << "Please enter the magnitude of t" << std::endl;
      d = inputvalue();
      
      res = vectorlength4(a,b,c,d);
      std::cout << " The length of this four-vector is " << res << std::endl;
    }

    else if(op == 'm'){
      std::cout << "Please enter the E1(GeV)" << std::endl;
      a = inputvalue();
      std::cout << "Please enter the P1(GeV)" << std::endl;
      b = inputvalue();
      std::cout << "Please enter the E2(GeV)" << std::endl;
      c = inputvalue();
      std::cout << "Please enter the P2(GeV)" << std::endl;
      d = inputvalue();
      std::cout << "Angle between the collision? (180 = head one!)" 
		<< std::endl;
      theta = inputvalue();
      res = invmass(a,b,c,d,theta);
      std::cout << "The Inv mass of the system is " << res << " GeV"
		<< std::endl;
    }
  }
}
