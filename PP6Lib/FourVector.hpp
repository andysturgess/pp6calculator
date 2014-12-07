//! \file   FourVector.hpp
//! \author Andy Sturgess
//! \brief Declarations for FourVector

#ifndef FOURVECTOR_HH
#define FOURVECTOR_HH

#include <string>
#include "ThreeVector.hpp"

class FourVector {
public:
  //! Causal structure enum
  enum CausalType {
    TIMELIKE = 0,
    SPACELIKE,
    LIGHTLIKE
  };

  //! Default constructor
  FourVector();

  //! Copy constructor!
  FourVector(const FourVector& other);

  //! Constructor with Values t,x,y,z
  FourVector(const double t, const double x, const double y, const double z);

  //! Constructor with values t, and spatial values
  //! given by a ThreeVector v.
  FourVector(const double t, const ThreeVector& v);

  //! Copy-assignment operator 
  FourVector& operator=(const FourVector& other);

  //! Add a vector to this one
  FourVector& operator+=(const FourVector& rhs);

  //! Subtract a vector from this one
  FourVector& operator-=(const FourVector& rhs);

  //! Multiply components of this vector by a constant
  FourVector& operator*=(const double rhs);

  //! Multiply components of a FourVector by another
  FourVector& operator*=(const FourVector& rhs);
  
  //! Divide components of this vector by a constant
  FourVector& operator/=(const double rhs);

  //! Divide components of a FourVector by another
  FourVector& operator/=(const FourVector& rhs);

  //! return the interval of the vector (Four_length!)
  double interval() const;

  //! boost the vector along the z-axis;
  int boost_z(const double velocity);

  //! return the causal type of the vector; 
  //! this uses our Enumeration at the start.
  CausalType getCausalType() const;
  
  //! return a string representation of this vector;
  //! Idea taken from Ben Morgan's examples; a much
  //! quicker way of doing it, without getI() and
  //! typing it in day3 menu etc!
  std::string asString() const;

  //! get t x, y, z components of a vector;
  //! Define a ThreeVector to return x_;
  //! This builds a ThreeVector whose components
  //! are then accessed by getX() previously defined
  //! in ThreeVector class, and sets them as such.

  double getT() const {return t_;}
  const ThreeVector& getThreeVector() const {return x_;}
  double getX() const {return x_.getX();}
  double getY() const {return x_.getY();}
  double getZ() const {return x_.getZ();}

  //! set t, x, y, z components of vector;
  //! see the above comments!
  void setT(const double t); 
  void setThreeVector(const ThreeVector& v);
  void setX(const double x);
  void setY(const double y);
  void setZ(const double z);

private:
  //! recompute interval whenever components change, as before!
  void four_interval();

private:
  //! member variables; t_ is new to this list;
  //! instead of x,y,z; just have a three-vector
  //! which we can access!
  
  double t_;
  ThreeVector x_;
  double s_; // the current interval (l_ in three_vector)
};

//! Create a FourVector with components;
//! We use FourVector extensively, useful to have
//! a creator function!
FourVector* createFourVector(const double t, const double x, const double y,
                             const double z);

//! Destroy a FourVector instance, deleting 
//! the pointer and then setting it to zero

void destroyFourVector(FourVector *&p);

//! convert a CausalType to a string representation
//! Taken from BM example; had extensive problems
//! when defining CausalType as a free enum previously..
//! (couldn't compile!)

std::string asString(const FourVector::CausalType k);

//! Instream and outstream to declare >>,<< as seen in ThreeVec

std::istream& operator>>(std::istream& in, FourVector& vec);
std::ostream& operator<<(std::ostream& out, const FourVector& vec);

//! Free functions; they allow us to add,subtract,divide and multiply
//! our FourVectors later on.

FourVector operator+(const FourVector& lhs, const FourVector& rhs);
FourVector operator-(const FourVector& lhs, const FourVector& rhs);
FourVector operator*(const FourVector& lhs, const double rhs);
FourVector operator*(const double lhs, const FourVector& rhs);
FourVector operator*(const FourVector& lhs, const FourVector& rhs);
FourVector operator/(const FourVector& lhs, const double rhs);
FourVector operator/(const FourVector& lhs, const FourVector& rhs);

#endif //FOURVECTOR_HH
