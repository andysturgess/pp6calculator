//! file   =  Particle.hpp
//! Author =  Andy Sturgess
//! Descr. =  Declarations for the Particle class

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <string>
#include <vector>
#include "ThreeVector.hpp"
#include "FourVector.hpp"

class Particle {
public:
 
  //! Default constructor - used in Muon Analysis!
  Particle();
  
  //! Copy constructor for Particle.
  Particle(const Particle& other);

  //! Constructor with pdgID, mass but ZERO momentum
  //! i.e a particle at rest!
  Particle(const int pdgID, const double mass);

  //! Constructor but with non-zero momentum; defined using
  //! a threevector 'momentum'.
  Particle(const int pdgID, const double mass, const ThreeVector& momentum);
  
  //! Constructor, same as above but with individual elements.
  Particle(const int pdgID, const double mass, const double px, 
	   const double py, const double pz);

  //! Copy Constructor assignment operator.
  Particle& operator=(const Particle& other);
  

  //! Gets the PDG code for a particle.
  int getPDGID() const { return pdgID_; }

  //! Gets the Mass of a particle.
  double getMassGeV() const { return mass_; }

  //! gets the Four Momentum for a particle
  //! returning momentum_.
  const FourVector& getFourMomentum() const { return momentum_; }

  //! gets the three Momentum for a particle
  //! returning momentum.getThreeVector(), so
  //! uses .getThreeVector() to extract x,y,z
  const ThreeVector& getThreeMomentum() const {return momentum_.getThreeVector(); }

  //! Naturally the magnitude of ThreeMom is the length
  //! of the obtained ThreeMom for a particle
  double getMagMomentum() const { return getThreeMomentum().length(); }

  //! The Energy of a particle is the T component of the Four Momenta
  double getEnergy() const { return momentum_.getT(); }

  //! Setting the PDGcode for a particle
  void setPDGID(const int pdgID) { pdgID_ = pdgID; }

  //! Setting the mass for a particle
  void setMass(const double mass);

  //! Setting the ThreeMomentum for a particle
  //! using ThreeVector class;
  void setThreeMomentum(const ThreeVector& p);

  //! Setting ThreeMom using individual elements!
  void setThreeMomentum(const double px, const double py, const double pz);

private:
  //! Member variables for ID, mass and momentum.
  //! Everything we need!
  int pdgID_;
  double mass_;
  FourVector momentum_;
};

//! invariant mass calculation for two particles;
double invariant_mass(const Particle& first, const Particle& second);

//! invariant mass calculation using a vector (array) of particles.
double invariant_mass(const std::vector<Particle>& particles);

#endif // PARTICLE_HPP
