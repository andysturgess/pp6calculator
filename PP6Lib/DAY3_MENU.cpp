#include "DAY3_MENU.hpp"
#include <iostream>
#include <limits>
#include "PP6Math.hpp"
#include "FourVector.hpp"
#include "MuClassAnalysis.hpp"


FourVector* userCreateFourVector(){
  double t(0), x(0), y(0), z(0);

  // Ask user for vector components
  std::cout << "Enter the t-component: ";
  t = inputvalue();
  std::cout << "Enter the x-component: ";
  x = inputvalue();
  std::cout << "Enter the y-component: ";
  y = inputvalue();
  std::cout << "Enter the z-component: ";
  z = inputvalue();

  return createFourVector(t, x, y, z);
}

void day3_menu(){
  double a(0), b(0), c(0), d(0), v(0);
  FourVector *Vec_one(0);
  FourVector *Vec_two(0);
  double velocity(0);
  double res(0);
  char op('\0');
  char cop('\0');

  while(true){
    std::cout << "PP6Calculator - DAY 3 MENU" << std::endl;
    std::cout << "==============================="<< std::endl;
    std::cout << "1) Using Structs" << std::endl;
    std::cout << "2) Using Classes" << std::endl;
    std::cout << "q) Quit " << std::endl;
    std::cin >> op;

    if(!std::cin){
      std::cerr << "[ERR] Please enter a valid operation" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }
    if(op == 'q') break;

    if(op == '1'){
      std::cout << "================STRUCTS================" << std::endl;
      std::cout << "=======================================" << std::endl;
      std::cout << "1) Boost in Z direction" << std::endl;
      std::cout << "2) Invariant Interval" << std::endl;
      std::cout << "3) Boost in Z using structs" << std::endl;
      std::cout << "4) Invariant Interval using structs" << std::endl;
      std::cout << "5) Boost in Z using structs" << std::endl;
      std::cout << "6) Invariant Interval using structs" << std::endl;
      std::cout << "q) Quit " << std::endl;
      std::cin >> cop;

      if(!std::cin){
	std::cerr << "[ERR] Please enter a valid operation" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }

      if(op == 'q') break;

      else if( cop == '1'){
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

      else if(cop == '2'){
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

      else if(cop == '3'){
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

      else if(cop == '4'){
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

      else if(cop == '5'){
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

      else if(cop == '6'){
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
    }
    //=====================================================================
    // CLASSES SECTION : Completely changed; couldn't find solutions to bugs!
    // Changed to follow Ben Morgan's solutions for 3,4Vector.cpp/hpp
    //=====================================================================
  
    if(op =='2'){
      std::cout << "=======================================" << std::endl;
      std::cout << "==============CLASSES==================" << std::endl;
      std::cout << "1) Create a FourVector, calc interval " << std::endl;
      std::cout << "2) Create and Boost a four vector " << std::endl;
      std::cout << "3) Do numerical operations with two vectors" << std::endl;
      std::cout << "4) Causal type of a vector " << std::endl;
      std::cout << "5) Recalculate muon pairs (hw2)" << std::endl;
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
      if(cop == '2'){
	Vec_one = userCreateFourVector();
	std::cout << "Please input the particle velocity" << std::endl;
	velocity = inputvalue();
	Vec_one->boost_z(velocity);
	std::cout << "t' is now : " << Vec_one->getT() << std::endl;
	std::cout << "t' is now : " << Vec_one->getZ() << std::endl;
	destroyFourVector(Vec_one);
      }
      
      if(cop == '3'){
	std::cout << "Input for FourVector 1 " << std::endl;
	Vec_one = userCreateFourVector();
	std::cout << "Input for FourVector 1 " << std::endl;
	Vec_two = userCreateFourVector();
	
	FourVector sum = (*Vec_one) + (*Vec_two);
	FourVector sub = (*Vec_one) - (*Vec_two);
	FourVector pro = (*Vec_one) * (*Vec_two);
	FourVector div = (*Vec_one) / (*Vec_two);
	
	std::cout << "Vector 1 + Vector 2 = " << sum  << std::endl;
	std::cout << "Vector 1 - Vector 2 = " << sub  << std::endl;
	std::cout << "Vector 1 * Vector 2 = " << pro  << std::endl;
	std::cout << "Vector 1 / Vector 2 = " << div  << std::endl;

	destroyFourVector(Vec_one);
	destroyFourVector(Vec_two);
      }
      if(cop == '4'){
	 Vec_one = userCreateFourVector();
	 FourVector::CausalType d = Vec_one->getCausalType();
	 std::cout << "The Causality of " <<  Vec_one->asString() << " is " 
		   << asString(d) << std::endl;
	 destroyFourVector(Vec_one);
      }
      if(cop == '5'){
	res = muonanalysis_day3();
      }
    }
  }
}
  
  
