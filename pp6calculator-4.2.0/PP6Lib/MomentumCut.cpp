#include "MomentumCut.hpp"

#include <cmath>
#include <iostream>
#include <vector>

#include "PP6Particle.hpp"

MomentumCut::MomentumCut(std::string CutType, double firstVal)
  :CutType_(CutType), firstVal_(firstVal), secondVal_(0)
{}

MomentumCut::MomentumCut(std::string CutType, double firstVal, double secondVal)
  :CutType_(CutType), firstVal_(firstVal), secondVal_(secondVal)
{}

MomentumCut::~MomentumCut()
{}

bool MomentumCut::select(const Particle& input) const{
  double partMass = input.getMagMomentum();
  
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

std::vector<Particle> MomentumCut::select(const std::vector<Particle>& inputVec) const{

  std::vector<Particle> passedParticles;

  for(unsigned int i = 0; i < inputVec.size(); i++){
    bool pass = select(inputVec[i]);
    if(pass == true){
      passedParticles.push_back(inputVec[i]);
    }
  }
  return passedParticles;
}
      






