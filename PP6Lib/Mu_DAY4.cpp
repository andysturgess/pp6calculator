//! Mu_DAY4 definitions

#include "Mu_DAY4.hpp"

#include <algorithm>
#include <map>
#include <iostream>
#include <vector>

#include "FileReader.hpp"

#include "PP6Math.hpp"
#include "Particle.hpp"
#include "ParticleInfo.hpp"

#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>


    

int muonanalysis_day4(){

  //! =============================================
  //! We check to see if the database is good!
  //! =============================================
  const ParticleInfo& particleDB = ParticleInfo("pdg.dat");
  std::cout << "Checking pdg.dat " << std::endl;
  if(particleDB.getPDGID("B+") == 521){ 
    std::cout << "pdg.dat is good!" << std::endl;
  }
  else{
    std::cout << "ERROR" << std::endl;
    return 0;
  }

  //! ==========================================
  //! We set up pdg and masses for the analysis
  //! also, vectors to contain our information
  //! mapping would probably be better
  //! ==========================================

  int MuonID = particleDB.getPDGID("mu-");
  int Anti_MuonID = particleDB.getPDGID("mu+");
  double MuonMass = particleDB.getMassGeV(MuonID);
  std::vector<int> Event_mu, Event_amu;
  std::vector<double> px_mu, px_amu;
  std::vector<double> py_mu, py_amu;
  std::vector<double> pz_mu, pz_amu;
  std::vector<double> invMasses;
  std::vector<int> indices;
  std::vector<std::vector<double> > matr;

  std::vector<Particle> muon;
  std::vector<Particle> antimuon;

  //! ==========================================
  //! FileReader; we only fill data into vectors
  //! if the strings match what we want!
  //! ==========================================

  
  FileReader columns("ObsPart.dat");
  while (columns.nextLine()){
    if(columns.getField<std::string>(6) == "run4.dat"){

      if(columns.getField<std::string>(2) == "mu-"){    
	Event_mu.push_back(columns.getField<int>(1));
	px_mu.push_back(columns.getField<double>(3));
	py_mu.push_back(columns.getField<double>(4));
	pz_mu.push_back(columns.getField<double>(5));
      }
      if(columns.getField<std::string>(2) == "mu+"){    
	Event_amu.push_back(columns.getField<int>(1));
	px_amu.push_back(columns.getField<double>(3));
	py_amu.push_back(columns.getField<double>(4));
	pz_amu.push_back(columns.getField<double>(5));
      }
    }
  }

  //! ==========================================
  //! Iterators, a better type of loop!
  //! ==========================================
  
  std::vector<int>::iterator iterMu(Event_mu.begin());
  std::vector<int>::iterator iterAmu(Event_amu.begin());
  std::vector<int>::iterator stopMu(Event_mu.end());
  std::vector<int>::iterator stopAmu(Event_amu.end()); 
  std::vector<double>::iterator px_muit(px_mu.begin());
  std::vector<double>::iterator py_muit(py_mu.begin());
  std::vector<double>::iterator pz_muit(pz_mu.begin());
  std::vector<double>::iterator px_amuit(px_amu.begin());
  std::vector<double>::iterator py_amuit(py_amu.begin());
  std::vector<double>::iterator pz_amuit(pz_amu.begin());
  

  for(; iterMu != stopMu; ++iterMu, ++px_muit, ++py_muit, ++pz_muit){
    muon.push_back(Particle(MuonID, MuonMass, *px_muit, *py_muit, *pz_muit));
 
  }

  for(; iterAmu != stopAmu; ++iterAmu, ++px_amuit, ++py_amuit, ++pz_amuit){
    antimuon.push_back(Particle(Anti_MuonID, MuonMass, *px_amuit, *py_amuit, *pz_amuit));
  }

  //! ==========================================
  //! we do the invariant mass calculation
  //! ==========================================

  for(unsigned int k = 0; k < Event_mu.size(); k++){
    for(unsigned int j = 0; j < Event_amu.size(); j++){
      invMasses.push_back(invariant_mass(muon[k],antimuon[j]));
      indices.push_back(k * Event_amu.size() + j);
    }
  }

  
  std::sort(invMasses.begin(), invMasses.end(), std::greater<double>());
	  
  for(int s = 0; s < 10; s++){
    std::cout << invMasses[s] << std::endl;
    std::cout << "mu :" << Event_mu[indices[s]] << "amu : " <<  Event_amu[indices[s]] <<std::endl;
  }
  

  return 0;
}



 
