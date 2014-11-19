// DAY2_MENU.cpp = Definitions for day 2's menu

#include "DAY2_MENU.hpp"
#include "PP6Math.hpp"
#include "MUONANALYSIS.hpp"

#include <cmath>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <limits>

void day2_menu(){
  double a(0), b(0);
  double bubble_array[5];
  std::pair<double,double> ReturnAVGandSTDDEV;
  char op('\0');

  while (true){
   
    std::cout << "PP6Calculator - DAY 2 MENU" << std::endl;
    std::cout << "=============================================" << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "s  = swap variables" << std::endl;
    std::cout << "b  = bubble sort variables" << std::endl;
    std::cout << "e  = AVG E and STDDEV of 100 random particles" << std::endl;
    std::cout << "g = read the data file ObservedParticles.dat" << std::endl;
    std::cout << "=============================================" << std::endl;
    
    std::cin >> op;
    if(!std::cin){
      std::cout<< "[ERR] Please input a valid operation!" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    if(op == 'q') break;
    
    else if (op == 's'){
      std::cout << " Please enter your first number " << std::endl;
      a = inputvalue();
      std::cout << " Please enter your second number " << std::endl;
      b = inputvalue();
      
      std::cout << " a is = " << a << " and b is = " << b << std::endl;
      swap(a,b);
      std::cout << " a is = " << a << " and b is = " << b << std::endl;
    }

    else if(op == 'b'){
      std::cout << "Please enter five numbers" << std::endl;
      for(int j = 0; j < 5; j++){
	std::cin >> bubble_array[j];
      }	
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }
      std::cout << " The array has now been bubble sorted.." << std::endl;
      Bubble(bubble_array);
      for(int i = 0; i < 5; i++){
	std::cout << bubble_array[i] << std::endl;
      }
    }
    
    else if(op == 'e'){
      ReturnAVGandSTDDEV = SPECTRUM();
      std::cout << "Average energy is (" << ReturnAVGandSTDDEV.first
		<< "+/-" << ReturnAVGandSTDDEV.second << ") GeV"
		<< std::endl;
    }
    
    else if(op == 'g'){
      muon_pairs();
    }
  }
}

   
