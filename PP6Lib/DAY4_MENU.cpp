#include "DAY4_MENU.hpp"
#include <iostream>
#include <limits>
#include <vector>
#include "PP6Math.hpp"
#include "FileReader.hpp"

void day4_menu(){
  char op('\0');
  
  while(true){
    std::cout << "PP6Calculator - DAY 4 MENU" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "1) Exercise 1" << std::endl;
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
      FileReader columns("pdg.dat");
      if (!columns.isValid()) {
	std::cerr << "[ERR] invalid file" << std::endl;
	continue;
      }
      /*
      std::vector<std::string> PartName;
      std::vector<int> PDG;
      std::vector<int> PartCharge;
      std::vector<double> PartMass;
      
      while (columns.nextLine()){
	PartName = columns.getField(1);
	if (columns.inputFailed()) continue;
	
	PDG = columns.getField(2);
	if (columns.inputFailed()) continue;

	PartCharge = columns.getField(3);
	if (columns.inputFailed()) continue;

	PartMass = columns.getField(4);
	if (columns.inputFailed()) continue;
      }

      for (int i = 0; i < PartName.size(); i++){
	std::cout << "Particle " << " PDG " <<  " Charge " << " Mass " << std::endl;
	std::cout << Partname[i] << "       " << PDG[i]<< "      " << Charge[i]
		  << "        "  << Mass[i] << std::endl;
      }
      
      */
    }
  }
}

    
    
