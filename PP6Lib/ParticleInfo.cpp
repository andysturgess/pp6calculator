//! ParticleInfo.cpp

#include "ParticleInfo.hpp"
#include <cmath>
#include "FileReader.hpp"

ParticleInfo::ParticleInfo(std::string database){

  //! We open a FileReader to supply the database
  FileReader readData(database);

  //! Check if the file is valid!
  if(readData.isValid()){
    std::string name;
    int pdg(0), charge(0);
    double mass(0.0);
    
    //! Use while loop, and then assign
    //! the data to its correct name
    while(readData.nextLine()){
      name = readData.getField<std::string>(1);
      pdg = readData.getField<int>(2);
      charge = readData.getField<int>(3);
      mass = readData.getField<double>(4);

      //! now we fill with pairs!
      
      convertNametoID.insert(std::make_pair(name,pdg));
      convertIDtoName.insert(std::make_pair(pdg,name));
      convertIDtoCharge.insert(std::make_pair(pdg,charge));
      convertIDtoMass.insert(std::make_pair(pdg,mass));
    }
  }
}

size_t ParticleInfo::size() const{
  return convertIDtoName.size();
}

int ParticleInfo::getPDGID(const std::string& name) const{
  std::map<std::string, int>::const_iterator iter = convertNametoID.find(name);
  if(iter != convertNametoID.end()){return iter->second;}
  else{ return 0;}
}

int ParticleInfo::getCharge(const int part) const{
  std::map<int,int>::const_iterator iter = convertIDtoCharge.find(part);
  if(iter != convertIDtoCharge.end()){return iter->second;}
  else{ return 0;}
}

std::string ParticleInfo::getName(const int part) const{
  std::map<int,std::string>::const_iterator iter = convertIDtoName.find(part);
  if(iter!= convertIDtoName.end()){return iter->second;}
  else{return 0;}
}

double ParticleInfo::getMassMeV(const int part) const{
  std::map<int,double>::const_iterator iter = convertIDtoMass.find(part);
  if(iter != convertIDtoMass.end()){return iter->second;}
  else{ return 0;}
}

double ParticleInfo::getMassGeV(const int part) const{
  return this->getMassMeV(part)/1000.0;
}


