#include "Day5Menu.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>

#include "PP6Math.hpp"
#include "PP6Particle.hpp"
#include "PP6ParticleInfo.hpp"
#include "FileReader.hpp"

void day5_menu(){
  char op('\0');
  
  while(true){
    std::cout << "PP6Calculator - DAY 4 MENU" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "1) TEST MASS CUT" << std::endl;
    std::cout << "q) Quit" << std::endl;
    std::cout << "=======================================" << std::endl;

    std::cin >> op;
    if(op == 'q') break;  
    
    if(!std::cin){
      std::cerr << "[ERR] Please enter a valid operation" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }

    if(op == '1'){
      std::cout << "This is the output for pdg.dat" << std::endl;
    }
  }
}
