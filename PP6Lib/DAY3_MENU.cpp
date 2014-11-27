#include "DAY3_MENU.hpp"
#include <iostream>
#include <limits>
#include "PP6Math.hpp"
#include "ThreeVector.hpp"

void day3_menu(){
  double a(0), b(0), c(0), d(0), e(0), f(0), v(0);
  double res(0);
  char op('\0');
  
  while(true){
    std::cout << "PP6Calculator - DAY 3 MENU" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "1) Boost in Z direction" << std::endl;
    std::cout << "2) Invariant Interval" << std::endl;
    std::cout << "3) Boost in Z using structs" << std::endl;
    std::cout << "4) Invariant Interval using structs" << std::endl;
    std::cout << "3) Boost in Z using structs" << std::endl;
    std::cout << "4) Invariant Interval using structs" << std::endl;
    std::cout << "5) Boost using opaque pointer" << std::endl;
    std::cout << "6) Invariant using opaque pointer" << std::endl;
    std::cout << "7) Boost using constructors" << std::endl;
    std::cout << "a) Using threevector class" << std::endl;
    std::cout << "=====================================" << std::endl;
 
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

      FourVector q;

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

      FourVector q;

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
      FourVector *q;
      q = createFourVector();

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
      destroyFourVector(q);
      
    }
    else if(op == '6'){
      FourVector *q;
      q = createFourVector();
       

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
      destroyFourVector(q);  
    }

    if(op == '7'){
      
      std::cout << "Enter x " << std::endl;
      a = inputvalue();
      std::cout << "Enter y " << std::endl;
      b = inputvalue();
      std::cout << "Enter z " << std::endl;
      c = inputvalue();
      std::cout << "Enter t " << std::endl;
      d = inputvalue();
      std::cout << "Enter v " << std::endl;
      v = inputvalue();
       
      FourVectorclass g = FourVectorclass(a,b,c,d);
      g.boost_z(v);
      res = g.interval();
      std::cout << "interval: " << res << std::endl;
    }

    if(op == 'a'){
      std::cout<< "ThreeVector 1" << std::endl;
      std::cout << "Enter x " << std::endl;
      a = inputvalue();
      std::cout << "Enter y " << std::endl;
      b = inputvalue();
      std::cout << "Enter z " << std::endl;
      c = inputvalue();

      std::cout<< "ThreeVector 1" << std::endl;
      std::cout << "Enter x " << std::endl;
      d = inputvalue();
      std::cout << "Enter y " << std::endl;
      e = inputvalue();
      std::cout << "Enter z " << std::endl;
      f = inputvalue();
     
      
      ThreeVector g = ThreeVector(a,b,c);
      ThreeVector l = ThreeVector(d,e,f);
      ThreeVector add = l+g;
      ThreeVector sub = l-g;
      ThreeVector mul = l*g;
      ThreeVector div = l/g;
      res = ScalarProd(g,l);
      double l1= std::sqrt( g.three_length() );
      double l2= std::sqrt( l.three_length() );
      
      std::cout << "The Three length of Vector 1 is " << l1 << std::endl;
      std::cout << "The Three length of Vector 2 is " << l2 << std::endl;
      std::cout << "The Scalar Product of 1 and 2 " << res << std::endl;
      std::cout << "The result of adding these vectors (" 
		<< add.getX() << "," << add.getY() << "," 
		<< add.getZ() << ")" << std::endl;
      std::cout << "The result of subtracting these vectors (" 
		<< sub.getX() << ","<< sub.getY() << "," 
		<< sub.getZ() << ")" << std::endl;
      std::cout << "The result of multiplying these vectors (" 
		<< mul.getX() << "," << mul.getY() << "," 
		<< mul.getZ() << ")" << std::endl;
      std::cout << "The result of dividing these vectors (" 
		<< div.getX() << "," << div.getY() << "," 
		<< div.getZ() << ")" << std::endl;
  

    }
  }
}

