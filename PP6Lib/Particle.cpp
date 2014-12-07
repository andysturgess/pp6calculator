//! Particle.cpp  - Implementing our Particle Class

#include "Particle.hpp"
#include <cmath>


//! ------------------------------------------------------------------
//! Default/Copy constructors etc
//! ------------------------------------------------------------------

//! Default Particle with null pdg and mass
Particle::Particle()
  : pdgID_(0), mass_(0.0)
{}

//! Copy particle, using init list to assign a copy of particle values
Particle::Particle(const Particle& other)
  : pdgID_(other.pdgID_), mass_(other.mass_), momentum_(other.momentum_)
{}

//! Particle with init list but zero momentum; hence we have
//! a momentum with energy = mass, and zero ThreeMom
Particle::Particle(const int pdgID, const double mass)
  : pdgID_(pdgID), mass_(mass), momentum_(mass, ThreeVector())
{}

//! Particle with non-zero momentum; set the three momentum
//! as a threevector 'momentum'
Particle::Particle(const int pdgID, const double mass, const ThreeVector& momentum)
  : pdgID_(pdgID), mass_(mass){
  this->setThreeMomentum(momentum);
}

//! Particle with non-zero momentum; instead with individual
//! elements; then made into a threeVector and sets the momentum.
Particle::Particle(const int pdgID, const double mass, const double px, const double py, const double pz)
  : pdgID_(pdgID), mass_(mass){
  ThreeVector mom(px, py, pz);
  this->setThreeMomentum(mom);
}

//! ------------------------------------------------------------------
//! Particle Operators
//! ------------------------------------------------------------------

//! We define the equals operator; this is the only useful
//! arithmetic operator; others do not make sense!
Particle& Particle::operator=(const Particle& other){  
if(this != &other ){
      this->pdgID_ = other.pdgID_;
      this->mass_ = other.mass_;
      this->momentum_ = other.momentum_;
    }
  return *this;
}

//! ------------------------------------------------------------------
//! Particle Member Functions
//! ------------------------------------------------------------------

//! Setting particle mass as input, then calculate
//! the three momentum
void Particle::setMass(const double mass){
  mass_ = mass;
  this->setThreeMomentum(this->getThreeMomentum());
}

//! setting the three momentum; takes threevec p,
//! takes the length of this vector, then determines
//! energy using e^2 = p^2 + m^2; Sets this as E in
//! the momentum FourVec, and sets threemom
void Particle::setThreeMomentum(const ThreeVector& p){
  const double E = sqrt(p.length()* p.length() + mass_*mass_);
  momentum_.setT(E);
  momentum_.setThreeVector(p);
}

//! Sets three momentum without a mass
void Particle::setThreeMomentum(const double px, const double py, const double pz){
  ThreeVector p(px, py, pz);
  this->setThreeMomentum(p);
}

//! Invariant mass of two particles; makes two
//! fourvectors, sums them (using previous class operators)
//! then does the interval and sqrts = same as inv mass!
double invariant_mass(const Particle& first, const Particle& second){
  const FourVector& p1 = first.getFourMomentum();
  const FourVector& p2 = second.getFourMomentum();
  FourVector p_tot = p1 + p2;
  return sqrt(p_tot.interval());
}


//! Taken from Ben Morgans. Not used iterators yet, but couldn't
//! think how to use an array of them; seems a good approach!
double invariant_mass(const std::vector<Particle>& particles){
  FourVector p_tot;
  std::vector<Particle>::const_iterator iter = particles.begin();
  const std::vector<Particle>::const_iterator end = particles.end();
  for ( ; iter != end; ++iter ) {
    p_tot += iter->getFourMomentum();
  }
  return sqrt(p_tot.interval());
}
