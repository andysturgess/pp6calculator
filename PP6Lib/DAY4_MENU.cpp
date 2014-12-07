#include "DAY4_MENU.hpp"
#include <iostream>
#include <limits>
#include <vector>
#include <iomanip>
#include "PP6Math.hpp"
#include "FileReader.hpp"

void day4_menu(){
  
  std::string partName;
  int pdgID;
  int partCharge;
  double partMass;
  std::vector<std::string> partName_vec;
  std::vector<int> pdgID_vec;
  std::vector<int> partCharge_vec;
  std::vector<double> partMass_vec;
  
  
  char op('\0');
  
  while(true){
    std::cout << "PP6Calculator - DAY 4 MENU" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "1) Exercise 1 - Looking at pdg.dat" << std::endl;
    std::cout << "2) Exercise 2 - Store data into vectors" << std::endl;
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
      
      while(columns.nextLine()){
      partName = columns.getField<std::string>(1);
      pdgID = columns.getField<int>(2);
      partCharge = columns.getField<int>(3);
      partMass = columns.getField<double>(4);

      std::cout << partName << std::setw(20) << pdgID << std:: setw(15) 
		<< partCharge << std::setw(15) << partMass  
		<< std::endl;
	}
    }
    
    if(op == '2'){
      
      FileReader columns("pdg.dat");
      if (!columns.isValid()) {
	std::cerr << "[ERR] invalid file" << std::endl;
	continue;
      }
      
      while(columns.nextLine()){
	partName = columns.getField<std::string>(1);
	pdgID = columns.getField<int>(2);
	partCharge = columns.getField<int>(3);
	partMass = columns.getField<double>(4);

	partName_vec.push_back(partName);
	pdgID_vec.push_back(pdgID);
	partCharge_vec.push_back(partCharge);
	partMass_vec.push_back(partMass);
      }

      std::cout << "partName" << std::setw(10) << "pdgID" 
		<< std::setw(10) << "partCharge"
		<< std::setw(10) << "partMass" << std::endl;
      std::cout << "(size = " << partName_vec.size() << ")"
		<< std::setw(10) << "(size ="
		<< pdgID_vec.size() << ")" << std::setw(10) 
		<< "(size =" << partCharge_vec.size() << ")" 
		<< std::setw(10) << "(size ="
		<< partMass_vec.size() << ")" << std::setw(10)
		<< std::endl;
      for(unsigned int i = 0; i < partName_vec.size(); i++){
	std::cout << partName_vec[i] << std::setw(15) 
		  << pdgID_vec[i] << std::setw(15)
		  << partCharge_vec[i] << std::setw(15)
		  << partMass_vec[i] << std::endl;
      }
    }  
  }
}



    
    
