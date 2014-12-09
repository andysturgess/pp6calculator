//! File: ParticleInfo.hpp
//! Auth: Andy Sturgess
//! Desc: ParticleInfo class declarations!

#ifndef PARTICLEINFO_HH
#define PARTICLEINFO_HH

#include <map>
#include <string>

class ParticleInfo{
public:

  //!Default Particle Info
  //!Takes a string called database!
  ParticleInfo(std::string database);

  //! Standard destructor
  ~ParticleInfo() {}

  //!Member Functions

  //! Size, relating to the magnitude
  //! of the database
  size_t size() const;

  //! this function gets the PDGID from
  //! the name of the particle
  int getPDGID(const std::string& name) const;
  
  //! this function gets the CHARGE from
  //! the PDGID of the particle
  int getCharge(const int part) const;

  //! this function gets the NAME from
  //! the PDGID of the particle
  std::string getName(const int part) const;

  //! this function gets the MASS from
  //! the PDGID of the particle (MeV)
  double getMassMeV(const int part) const;

  //! this function gets the CHARGE from
  //! the PDGID of the particle (GeV)
  double getMassGeV(const int part) const;

private:
  //! the copy constructor!
  ParticleInfo(const ParticleInfo&);

  //! the copy assignment operator
  ParticleInfo& operator=(const ParticleInfo&);

  //member variables
  //! we will use maps for these, they are
  //! perfect for databasing! They take ID
  //! (from name/ or vice versa), and give
  //! the other variables!

  std::map<std::string,int> convertNametoID;
  std::map<int,std::string> convertIDtoName;
  std::map<int,int> convertIDtoCharge;
  std::map<int,double> convertIDtoMass;

};

#endif // PARTICLEINFO_HPP
