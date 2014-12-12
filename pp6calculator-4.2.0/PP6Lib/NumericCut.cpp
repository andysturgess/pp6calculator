#include "NumericCut.hpp"

#include <cmath>
#include <iostream>
#include <vector>

#include "PP6Particle.hpp"

NumericCut::NumericCut(std::string CutType, double firstVal)
  :CutType_(CutType), firstVal_(firstVal), secondVal_(0)
{}

NumericCut::NumericCut(std::string CutType, double firstVal, double secondVal)
  :CutType_(CutType), firstVal_(firstVal), secondVal_(secondVal)
{}

NumericCut::~NumericCut()
{}

bool NumericCut::select(const Particle& input) const{
  double cutVariable = input.getMassGeV();
  
  if(CutType_ == "greater"){
    if(cutVariable > firstVal_ ) {return true;}
    else {return false;}
  }
  else if (CutType_ == "lesser"){
    if(cutVariable < secondVal_ ) {return true;}
    else {return false;}
  }
  else if (CutType_ == "range"){
    if(firstVal_ < secondVal_ ){
      if((cutVariable > firstVal_ ) && (cutVariable < secondVal_ )){return true;}
      else {return false;}
    }
    else{
      if((cutVariable < firstVal_ ) && (cutVariable > secondVal_ )){return true;}
      else {return false;}
    }
  }
  else {return false;}
}

std::vector<Particle> NumericCut::select(const std::vector<Particle>& inputVec) const{

  std::vector<Particle> passedParticles;

  for(unsigned int i = 0; i < inputVec.size(); i++){
    bool pass = select(inputVec[i]);
    if(pass == true){
      passedParticles.push_back(inputVec[i]);
    }
  }
  return passedParticles;
}
