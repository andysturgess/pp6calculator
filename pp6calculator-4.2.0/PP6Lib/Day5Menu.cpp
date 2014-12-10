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
#include "EnergyCut.hpp"
#include "MomentumCut.hpp"

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

    std::cout << "=======================================" << std::endl;
    std::cout << "PP6Calculator - DAY 5 MENU" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "All operations are on particles.dat" << std::endl;
    std::cout << "1) MassCut (> 0.4 GeV) " << std::endl;
    std::cout << "2) EnergyCut ( 2 < E(GeV) < 2.5)" << std::endl;
    std::cout << "3) MomentumCut ( < 2.25 GeV) "<< std::endl;
    std::cout << "4) All Three? "<< std::endl;
    std::cout << "q) Quit " << std::endl;
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
     
      MassCut cutMass("greater", 0.4);           
      std::vector<Particle> passedParticles = (cutMass.select(particles_info()));

      std::cout << "Particles which pass " << std::endl;
      for(unsigned int i = 0; i < passedParticles.size(); ++i){
	std::cout << passedParticles[i] << std::endl;
      }
    }

    if(op == '2'){
     
      EnergyCut cutEnergy("range", 2.0, 2.5);           
      std::vector<Particle> passedParticles = (cutEnergy.select(particles_info()));

      std::cout << "Particles which pass " << std::endl;
      for(unsigned int i = 0; i < passedParticles.size(); ++i){
	std::cout << passedParticles[i] << std::endl;
      }
    }
    
    if(op == '3'){
     
      MomentumCut cutMom("lesser", 2.25);           
      std::vector<Particle> passedParticles = (cutMom.select(particles_info()));

      std::cout << "Particles which pass " << std::endl;
      for(unsigned int i = 0; i < passedParticles.size(); ++i){
	std::cout << passedParticles[i] << std::endl;
      }
    }

     if(op == '4'){
     
      MomentumCut cutMom("lesser", 2.25);  
      EnergyCut cutEnergy("range", 2.0, 2.5);    
      MassCut cutMass("greater", 0.4); 

      std::vector<Particle> Particles_mom = (cutMom.select(particles_info()));
      std::vector<Particle> Particles_mass = (cutMass.select(Particles_mom));
      std::vector<Particle> Particles_en = (cutMass.select(Particles_mass));

      std::cout << "Particles which pass " << std::endl;
      for(unsigned int i = 0; i < Particles_en.size(); ++i){
	std::cout << Particles_en[i] << std::endl;
      }
    }
  }
}

