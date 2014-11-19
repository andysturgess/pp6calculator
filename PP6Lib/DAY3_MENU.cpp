
#include "DAY3_MENU.hpp"
#include <iostream>
#include <limits>
#include "PP6Math.hpp"

void day3_menu(){
  double a(0), b(0), c(0), d(0), v(0);
  double res(0);
  char op('\0');
  
  while(true){
    std::cout << "PP6Calulator - DAY 3 MENU" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "1) Boost in Z direction" << std::endl;
    std::cout << "2) Invariant Interval" << std::endl;
    std::cout << "3) Boost in Z using structs" << std::endl;
    std::cout << "4) Invariant Interval using structs" << std::endl;
    std::cout << "3) Boost in Z using structs" << std::endl;
    std::cout << "4) Invariant Interval using structs" << std::endl;
    std::cout << "5) Boost using opaque pointer" << std::endl;
    std::cout << "6) Invariant using opaque pointer" << std::endl;
 
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

       opinterval(q);
       destroyFourVector(q);
      
    }

    

  }
}

  