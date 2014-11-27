//FourVector.cpp: Implementation of FourVector

#include <FourVector.hpp>
#include <cmath>
#include <iostream>
#include <sstream>


FourVector::FourVector(const FourVector& other)
  : t_(other.getT()), x_(other.getThreeVector()), s_(other.interval())
{}

FourVector::FourVector(const double t, const double x, const double y, const double z) : t_(t), x_(x, y, z){
  compute_interval();
}

FourVector::FourVector(const double t, const ThreeVector& x) : t_(t), x_(x){
  compute_interval();
}

//----------------------------------------------------------------------
// Member operators

FourVector& FourVector::operator=(const FourVector& other)
{
  if ( this != &other ) // Ignore attempts at self-assignment
  {
    t_ = other.getT();
    x_ = other.getThreeVector();
    s_ = other.interval();
  }
  return *this;
}

FourVector& FourVector::operator+=(const FourVector& rhs){
  t_ += rhs.getT();
  x_ += rhs.getThreeVector();
  compute_interval();
  return *this;
}

FourVector& FourVector::operator-=(const FourVector& rhs){
  t_ -= rhs.getT();
  x_ -= rhs.getThreeVector();
  compute_interval();
  return *this;
}

FourVector& FourVector::operator*=(const double rhs){
  t_ *= rhs;
  x_ *= rhs;
  compute_interval();
  return *this;
}

FourVector& FourVector::operator/=(const double rhs){
  t_ /= rhs;
  x_ /= rhs;
  compute_interval();
  return *this;
}

//----------------------------------------------------------------------
// Member functions
void FourVector::setT(double t){
  t_ = t;
  compute_interval();
}

void FourVector::setThreeVector(const ThreeVector& v){
  x_ = v;
  compute_interval();
}

void FourVector::setX(const double x){
  x_.setX(x);
}

void FourVector::setY(const double y){
  x_.setY(y);
}

void FourVector::setZ(const double z){
  x_.setZ(z);
}

double FourVector::interval() const{
  return s_;
}

int FourVector::boost_z(const double velocity){
  if ( velocity >= 1 ) // Cannot boost faster than speed of light
    {
      return 1; // Indicate error
    }

  // Calculate Lorentz factor
  double gamma = 1.0 / sqrt(1.0 - velocity * velocity);
  
  // Apply boost in z direction - need temp variables due to mixing
  double z_prime = gamma * ( x_.getZ() - velocity * t_);
  double t_prime = gamma * ( t_ - velocity * x_.getZ() );
  x_.setZ(z_prime);
  t_ = t_prime;

  return 0; // Indicate success
}

FourVector::CausalType FourVector::getCausalType() const{
  CausalType k = LIGHTLIKE;
  if (this->interval() > 0.0) {
    k = SPACELIKE;
  } else if (this->interval() < 0.0) {
    k = TIMELIKE;
  }
  return k;
}

void FourVector::compute_interval(){
  s_ = t_*t_ - x_.length()*x_.length();
}

//----------------------------------------------------------------------
// Free functions - we can retain these for convenience!

//! Create a new FourVector instance with components
FourVector* createFourVector(const double t, const double x, const double y,
                             const double z) {
  FourVector *p = new FourVector(t, x, y, z);
  return p;
}

//! Destroy a FourVector instance, nulling the supplied pointer
void destroyFourVector(FourVector *&p) {
  if (p)
    {
    delete p;
    p = 0;
    }
}


std::string asString(const FourVector::CausalType k){
  std::ostringstream s;
  s << "[";
  if (k == FourVector::TIMELIKE) {
    s << "timelike";
  } else if (k == FourVector::SPACELIKE) {
    s << "spacelike";
  } else if (k == FourVector::LIGHTLIKE) {
    s << "lightlike";
  } else {
    // Should really assert() or throw because we should *never* get here
    s << "INVALID";
  }

  s << "]";
  return s.str();
}

FourVector operator+(const FourVector& lhs, const FourVector& rhs)
{
  FourVector temp(lhs);
  temp += rhs;
  return temp;
}

FourVector operator-(const FourVector& lhs, const FourVector& rhs)
{
  FourVector temp(lhs);
  temp -= rhs;
  return temp;
}

FourVector operator*(const FourVector& lhs, const double rhs)
{
  FourVector temp(lhs);
  temp *= rhs;
  return temp;
}

FourVector operator*(const double lhs, const FourVector& rhs)
{
  FourVector temp(rhs);
  temp *= lhs;
  return temp;
}

FourVector operator/(const FourVector& lhs, const double rhs)
{
  FourVector temp(lhs);
  temp /= rhs;
  return temp;
}
