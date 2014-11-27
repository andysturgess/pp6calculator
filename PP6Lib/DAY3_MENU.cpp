#include "DAY3_MENU.hpp"
#include <iostream>
#include <limits>
#include "PP6Math.hpp"
#include "FourVector.hpp"

FourVector* userCreateFourVector(){
  double it(0), ix(0), iy(0), iz(0);

  // Ask user for vector components
  std::cout << "Enter the t-component: ";
  it = inputvalue();
  std::cout << "Enter the x-component: ";
  ix = inputvalue();
  std::cout << "Enter the y-component: ";
  iy = inputvalue();
  std::cout << "Enter the z-component: ";
  iz = inputvalue();

  return createFourVector(it, ix, iy, iz);
}

void day3_menu(){
  double a(0), b(0), c(0), d(0), v(0);
  FourVector *Vec_one(0); 
//*Vec_two(0);
  double res(0);
  char op('\0');
  char cop('\0');

  while(true){
    std::cout << "PP6Calculator - DAY 3 MENU" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "================STRUCTS================" << std::endl;
    std::cout << "1) Boost in Z direction" << std::endl;
    std::cout << "2) Invariant Interval" << std::endl;
    std::cout << "3) Boost in Z using structs" << std::endl;
    std::cout << "4) Invariant Interval using structs" << std::endl;
    std::cout << "5) Boost in Z using structs" << std::endl;
    std::cout << "6) Invariant Interval using structs" << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "=====PRESS 'C' FOR CLASSES MENU======" << std::endl;
    std::cin >> op;

    if(!std::cin){
      std::cerr << "[ERR] Please enter a valid operation" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }

    if(op == 'q') break;

    else if( op == '1'){
      std::cout << "Please enter the x component" << std::endl;
      a = inputvalue();
      std::cout << "Please enter the y component" << std::endl;
      b = inputvalue();
      std::cout << "Please enter the z component" << std::endl;
      c = inputvalue();
      std::cout << "Please enter the t component" << std::endl;
      d = inputvalue();
      std::cout << "Please enter the value of beta (v/c)" << std::endl;
      v = inputvalue();
      boostalongz(a,b,c,d,v);

      std::cout << "the result of the boost: " << std::endl;
      std::cout << " x is " << a << std::endl;
      std::cout << " y is " << b << std::endl;
      std::cout << " z is " << c << std::endl;
      std::cout << " t is " << d << std::endl;
    }

    else if(op == '2'){
      std::cout << "Please enter the x component" << std::endl;
      a = inputvalue();
      std::cout << "Please enter the y component" << std::endl;
      b = inputvalue();
      std::cout << "Please enter the z component" << std::endl;
      c = inputvalue();
      std::cout << "Please enter the t component" << std::endl;
      d = inputvalue();
      res = vectorlength4(a,b,c,d);
      std::cout << " the invariant interval is " << res << std::endl;
    }

    else if(op == '3'){
      FourVec q;
      std::cout << "Please enter the x component" << std::endl;
      q.x = inputvalue();
      std::cout << "Please enter the y component" << std::endl;
      q.y = inputvalue();
      std::cout << "Please enter the z component" << std::endl;
      q.z = inputvalue();
      std::cout << "Please enter the t component" << std::endl;
      q.t = inputvalue();
      std::cout << "Please enter the value of beta (v/c)" << std::endl;
      v = inputvalue();
      boostz(q,v);
    }

    else if(op == '4'){
      FourVec q;
      std::cout << "Please enter the x component" << std::endl;
      q.x = inputvalue();
      std::cout << "Please enter the y component" << std::endl;
      q.y = inputvalue();
      std::cout << "Please enter the z component" << std::endl;
      q.z = inputvalue();
      std::cout << "Please enter the t component" << std::endl;
      q.t = inputvalue();
      double res = invint(q);
      std::cout << " the invariant interval is " << res << std::endl;
    }

    else if(op == '5'){
      FourVec *q;
      q = createFourVec();
      std::cout << "Please enter the x component" << std::endl;
      q->x = inputvalue();
      std::cout << "Please enter the y component" << std::endl;
      q->y = inputvalue();
      std::cout << "Please enter the z component" << std::endl;
      q->z = inputvalue();
      std::cout << "Please enter the t component" << std::endl;
      q->t = inputvalue();
      std::cout << "Please enter the v component" << std::endl;
      v = inputvalue();
      evalboostz(q,v);
      destroyFourVec(q);
    }

    else if(op == '6'){
      FourVec *q;
      q = createFourVec();
      std::cout << "Please enter the x component" << std::endl;
      q->x = inputvalue();
      std::cout << "Please enter the y component" << std::endl;
      q->y = inputvalue();
      std::cout << "Please enter the z component" << std::endl;
      q->z = inputvalue();
      std::cout << "Please enter the t component" << std::endl;
      q->t = inputvalue();
      InvariantSign t = getInvariantSign(q);
      opinterval(q);

      if(t == TIMELIKE){
	std::cout<< "TIMELIKE: causally connected!" << std::endl;
      }
      if(t == SPACELIKE){
	std::cout<< "SPACELIKE: not causally connected!" << std::endl;
      }
      if(t == LIGHTLIKE){
	std::cout<< "NULL: connected by lightlike world lines!" << std::endl;
      }
      destroyFourVec(q);

    }
    //=====================================================================
    // CLASSES SECTION : Completely changed; couldn't find solutions to bugs!
    // Changed to follow Ben Morgan's solutions for 3,4Vector.cpp/hpp
    //=====================================================================
  
    if(op =='c'){
     
      std::cout << "PP6Calculator - DAY 3 MENU" << std::endl;
      std::cout << "=======================================" << std::endl;
      std::cout << "==============CLASSES==================" << std::endl;
      std::cout << "1) Create a FourVector, calc interval " << std::endl;
      std::cout << "2) Create and Boost a four vector " << std::endl;
      std::cout << "3) Do numerical operations with two vectors" << std::endl;
      std::cout << "q) Quit." << std::endl;
      
      std::cin >> cop;
      
      if(!std::cin){
	std::cerr << "[ERR] Please enter a valid operation" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }

      if(cop == 'q') break;
      if(cop == '1'){
	Vec_one = userCreateFourVector();
	std::cout << "interval = " <<	Vec_one->interval() << std::endl;
	destroyFourVector(Vec_one);

      }	 
    }
  }
}
  
