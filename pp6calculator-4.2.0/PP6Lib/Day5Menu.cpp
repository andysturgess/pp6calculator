#include "Day5Menu.hpp"


#include <iostream>
#include <limits>
#include <vector>

#include "FileReader.hpp"

#include "PP6Math.hpp"
#include "PP6Particle.hpp"
#include "PP6ParticleInfo.hpp"
#include "Cut.hpp"
#include "MassCut.hpp"

//! ===========================================
//! This function stores our data, and returns
//! a vector (particleData) which contains all
//! information from particles.dat
//! ===========================================

std::vector<Particle> particles_info(){
  std::vector<Particle> particleData;
  FileReader data("particles.dat");
      
  if(data.isValid()){
    std::cout << "data is VALID" << std::endl;
    data.nextLine();
    while(data.nextLine()){
      Particle input = data.getLine<Particle>();
      particleData.push_back(input);
    }
  }
  return particleData;
}

//! --------------------------------------------------------------------
//! MAIN PROGRAM
//! --------------------------------------------------------------------

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

    //! ===================================================
    //! Use MassCut class to build a condition "greater".
    //! We then make a vector, equal to masscut on another
    //! vector, supplied by particles_info function.
    //! ===================================================

    if(op == '1'){
     
      MassCut masscut("greater", 0.4);           
      std::vector<Particle> passedParticles (masscut.select(particles_info()));

      std::cout << "Particles which pass " << std::endl;
      for(unsigned int i = 0; i < passedParticles.size(); ++i){
	std::cout << passedParticles[i] << std::endl;
      
    }
  }
}

