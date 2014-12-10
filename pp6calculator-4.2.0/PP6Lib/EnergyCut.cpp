#include "EnergyCut.hpp"

#include <cmath>
#include <iostream>
#include <vector>

#include "PP6Particle.hpp"

EnergyCut::EnergyCut(std::string CutType, double firstVal)
  :CutType_(CutType), firstVal_(firstVal), secondVal_(0)
{}

EnergyCut::EnergyCut(std::string CutType, double firstVal, double secondVal)
  :CutType_(CutType), firstVal_(firstVal), secondVal_(secondVal)
{}

EnergyCut::~EnergyCut()
{}

bool EnergyCut::select(const Particle& input) const{
  double partMass = input.getEnergy();
  
  if(CutType_ == "greater"){
    if(partMass > firstVal_ ) {return true;}
    else {return false;}
  }
  else if (CutType_ == "lesser"){
    if(partMass < firstVal_ ) {return true;}
    else {return false;}
  }
  else if (CutType_ == "range"){
    if(firstVal_ < secondVal_ ){
      if((partMass > firstVal_ ) && (partMass < secondVal_ )){return true;}
      else {return false;}
    }
    else{
      if((partMass < firstVal_ ) && (partMass > secondVal_ )){return true;}
      else {return false;}
    }
  }
  else {return false;}
}

std::vector<Particle> EnergyCut::select(const std::vector<Particle>& inputVec) const{

  std::vector<Particle> passedParticles;

  for(unsigned int i = 0; i < inputVec.size(); i++){
    bool pass = select(inputVec[i]);
    if(pass == true){
      passedParticles.push_back(inputVec[i]);
    }
  }
  return passedParticles;
}
      






