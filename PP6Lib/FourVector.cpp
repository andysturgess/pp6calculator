//! FourVector.cpp: Implementation of FourVector

#include "FourVector.hpp"
#include <cmath>
#include <sstream>


//! Function to calculate the length of the Fourvector
//! put at start of input so I dont confuse myself...
//! calculate the length for each type of FourVector!

void FourVector::four_interval(){
  s_ = t_*t_ - x_.length()*x_.length();
}

//!--------------------------------------------------------------------
//! FourVector Definitions
//!--------------------------------------------------------------------

//! Default FourVector Definition
FourVector::FourVector() : t_(0.0), x_(), s_(0.0)
{}

//! Copy Constructor with initialiser list; sets t_,
//! x_ and s_ to equal another FourVector.
FourVector::FourVector(const FourVector& other)
  : t_(other.getT()), x_(other.getThreeVector()), s_(other.interval())
{}

//! Constructor with all four values t,x,y,z
FourVector::FourVector(const double t, const double x, 
		       const double y, const double z)
  : t_(t), x_(x, y, z){
  four_interval();
}

//! Constructor with t and spatial values given
//! by a ThreeVector x. Uses init list to set values!
FourVector::FourVector(const double t, const ThreeVector& x) 
  : t_(t), x_(x){
  four_interval();
}

//! --------------------------------------------------------------------
//! Member operators - define iterator functions
//! -------------------------------------------------------------------

//! Copy assignment operator
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

//! Define operator += for adding FourVectors; instead of
//! getI() for threevectors, uses getT and getThreeVector
//! and then determines the interval.

FourVector& FourVector::operator+=(const FourVector& rhs){
  t_ += rhs.getT();
  x_ += rhs.getThreeVector();
  four_interval();
  return *this;
}

//! Define operator -= for subtracting FourVectors; 

FourVector& FourVector::operator-=(const FourVector& rhs){
  t_ -= rhs.getT();
  x_ -= rhs.getThreeVector();
  four_interval();
  return *this;
}

//! Define operator *= for multiplying FourVector
//! elements by a constant number

FourVector& FourVector::operator*=(const double rhs){
  t_ *= rhs;
  x_ *= rhs;
  four_interval();
  return *this;
}

//! Define operator *= for multiplying FourVector
//! elements by another FourVector! (a bit like a
//! four element scalar product)

FourVector& FourVector::operator*=(const FourVector& rhs){
  t_ *= rhs.getT();
  x_ *= rhs.getThreeVector();
  four_interval();
  return *this;
}

//! Define operator /= for dividing FourVector 
//! elements by a constant number.


FourVector& FourVector::operator/=(const double rhs){
  t_ /= rhs;
  x_ /= rhs;
  four_interval();
  return *this;
}

//! Define operator /= for dividing FourVector elements,
//! by the elements of another FourVector (like scalar 
//! product, but dotting with reciprocal!).

FourVector& FourVector::operator/=(const FourVector& rhs){
  t_ /= rhs.getT();
  x_ /= rhs.getThreeVector();
  four_interval();
  return *this;
}

//----------------------------------------------------------------------
// Member functions
// ---------------------------------------------------------------------

//! Setting the value of t within our FourVector
//! Then returns in the interval
void FourVector::setT(double t){
  t_ = t;
  four_interval();
}

//! Setting the value of the ThreeVector within 
//! our FourVector, Then returns in the interval
void FourVector::setThreeVector(const ThreeVector& v){
  x_ = v;
  four_interval();
}

//! Individually setting the elements of the
//! ThreeVector inside the fourvector.
void FourVector::setX(const double x){
  x_.setX(x);
}

void FourVector::setY(const double y){
  x_.setY(y);
}

void FourVector::setZ(const double z){
  x_.setZ(z);
}

//! Returns the value of the interval!
double FourVector::interval() const{
  return s_;
}

//! This is the boost function; it firstly checks if beta
//! is greater than 1 (impossible!). As this is a boost in
//! z, it changes the magnitude of only t and z. They are
//! denoted z',t'.
int FourVector::boost_z(const double beta){
  if(beta >= 1){
    return 1;
  }
  double gamma = 1.0 / sqrt(1.0 - beta * beta);
  double z_prime = gamma * ( x_.getZ() - beta * t_);
  double t_prime = gamma * ( t_ - beta * x_.getZ() );
  x_.setZ(z_prime);
  t_ = t_prime;

  return 0; 
}

//! CausalType tells us the causality type of an inputted
//! FourVector. Uses the interval value! (had trouble with
//! this initially, due to declaring functions as free)
FourVector::CausalType FourVector::getCausalType() const{
  CausalType k = LIGHTLIKE;
  if (this->interval() > 0.0) {
    k = SPACELIKE;
  } else if (this->interval() < 0.0) {
    k = TIMELIKE;
  }
  return k;
}

//! Taken from Ben Morgan's. Used to display our vectors
//! As a string! much better than outputting each element.
std::string FourVector::asString() const{
  std::ostringstream s;
  s << *this;
  return s.str();
}

//----------------------------------------------------------------------
// Free functions - we can retain these for convenience!
//----------------------------------------------------------------------

//! Create a new FourVector instance with components
//! Inputted by the user!
FourVector* createFourVector(const double t, const double x, const double y,
                             const double z) {
  FourVector *p = new FourVector(t, x, y, z);
  return p;
}

//! Destroy a FourVector instance. Takes the pointer,
//! deletes and then Null's it!
void destroyFourVector(FourVector *&p) {
  if (p)
    {
    delete p;
    p = 0;
    }
}


//! Returns the enumeration as a String when called
//! Only way I could see this working is BM's (again)
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
    s << "INVALID";
  }
  s << "]";
  return s.str();
}
//! Instream and outstreaming operators >> <<, useful in
//! day3 menu interface!

std::istream& operator>>(std::istream& in, FourVector& vec) {
  double t(0.0);
  ThreeVector p3;
  std::string dummy;
  in >> dummy >> t >> dummy >> p3 >> dummy;
  vec.setT(t);
  vec.setThreeVector(p3);
  return in;
}
std::ostream& operator<<(std::ostream& out, const FourVector& vec){
  out << "( " << vec.getT() << " , " << vec.getThreeVector() << " )";
  return out;
}

//! Free operator = adds two FourVectors together!
FourVector operator+(const FourVector& lhs, const FourVector& rhs){
  FourVector temp(lhs);
  temp += rhs;
  return temp;
}

//! Free operator = subtracts two FourVectors
FourVector operator-(const FourVector& lhs, const FourVector& rhs){
  FourVector temp(lhs);
  temp -= rhs;
  return temp;
}

//! Free operator = multiplies a four vector with a constant(rhs)
FourVector operator*(const FourVector& lhs, const double rhs){
  FourVector temp(lhs);
  temp *= rhs;
  return temp;
}

//! Free operator = multiplies a four vector with a constant(lhs)
FourVector operator*(const double lhs, const FourVector& rhs){
  FourVector temp(rhs);
  temp *= lhs;
  return temp;
}

//! Free operator = multiplies a four vector with another
FourVector operator*(const FourVector& lhs, const FourVector& rhs){
  FourVector temp(rhs);
  temp *= lhs;
  return temp;
}

//! Free operator = divides a four vector by a constant(lhs)
FourVector operator/(const FourVector& lhs, const double rhs){
  FourVector temp(lhs);
  temp /= rhs;
  return temp;
}

//! Free operator = divides a four vector by another
FourVector operator/(const FourVector& lhs, const FourVector& rhs){
 FourVector temp(lhs);
  temp /= rhs;
  return temp;
}
