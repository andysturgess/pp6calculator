#include "DAY4_MENU.hpp"

#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <cstdlib>

#include "PP6Math.hpp"
#include "ParticleInfo.hpp"
#include "FileReader.hpp"

int readData(){
  FileReader dbase("pdg.dat");
  if(!dbase.isValid()){
    std::cerr << "ERROR" << std::endl;
    return 1;
  }

  std::vector<std::string> partName;
  std::vector<int> pdgID;
  std::vector<int> partCharge;
  std::vector<double> partMass;

  while(dbase.nextLine()){
    partName.push_back(dbase.getField<std::string>(1));
    pdgID.push_back(dbase.getField<int>(2));
    partCharge.push_back(dbase.getField<int>(3));
    partMass.push_back(dbase.getField<double>(4));
  }

  std::vector<std::string>::iterator iterName(partName.begin());
  std::vector<std::string>::iterator iterSTOP(partName.end());
  std::vector<int>::iterator iterID(pdgID.begin());
  std::vector<int>::iterator iterCharge(partCharge.begin());
  std::vector<double>::iterator iterMass(partMass.begin());

  for(; iterName != iterSTOP; ++iterName, ++iterID, ++iterCharge, ++iterMass){
    std::cout << *iterName << " "
	      << *iterID << " "
	      << *iterCharge << " "
	      << *iterMass << std::endl;
  }
  return 0;
}

int checkParticleInfo(){
  const ParticleInfo& database = ParticleInfo("pdg.dat");
  std::cout << "These are a quick series of checks" << std::endl;
  
  std::cout << "Checking if we get correct B+ ID" << std::endl;
  if(database.getPDGID("B+") != 521){ 
    std::cout << "INCORRECT" << std::endl;
    return 1;
  }
  else{
    std::cout << "CORRECT" << std::endl;
  }
  
  std::cout << "Checking if we get correct B+ Mass" << std::endl;
  double M = database.getMassGeV(521);
  double R = 5.27917/M;
  if(R == 1){ std::cout << "CORRECT!" << std::endl;}
  else {std::cout << "INCORRECT!" << std::endl;}
  return 0;
}

int algorithms(){

  size_t s(0);

  std::cout << "Enter size of array to generate/sort [5 <= N <= 50]: ";

  s = inputvalue();

  if((s > 4) && (s < 51)){
   
    std::vector<double> STLVec(s,0);

    std::generate(STLVec.begin(), STLVec.end(), getRandom );
 
    std::cout << "The Vector looks like:" << std::endl;
    std::copy(STLVec.begin(), STLVec.end(), std::ostream_iterator<double>(std::cout, "\n"));
  
    std::vector<double>::iterator maxElem = std::max_element(STLVec.begin(), STLVec.end());
    std::vector<double>::iterator minElem = std::min_element(STLVec.begin(), STLVec.end());

    std::cout << "Max Element = " << *maxElem << std::endl;
    std::cout << "Min Element = " << *minElem << std::endl;

    std::sort(STLVec.begin(),STLVec.end());
    std::cout << "The result of the sort" << std::endl;
    std::copy(STLVec.begin(), STLVec.end(), std::ostream_iterator<double>(std::cout, "\n"));

  }
  else{
    std::cout << "hey, enter something in the right range" << std::endl;
  }

  return 0;
}


//!===============================================================================

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
    std::cout << "3) Exercise 3 - Same but with iterators" << std::endl;
    std::cout << "4) Exercise 4 - Checking ParticleInfo" << std::endl;
    std::cout << "5) Exercise 5 - Algorithm task" << std::endl;
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
    
    else if(op == '2'){
      
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
    
    else if (op == '3'){
      readData();
    }

    else if( op == '4'){
      checkParticleInfo();
    }

    else if( op == '5'){
      algorithms();
    }


  
  }
}
