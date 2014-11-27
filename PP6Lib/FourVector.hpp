//! \file   FourVector.hpp
//! \author Andy Sturgess
//! \brief Declarations for FourVector

#ifndef FOURVECTOR_HH
#define FOURVECTOR_HH

#include <string>

#include <iostream>
#include "ThreeVector.hpp"

class FourVector {
public:
  //! Causal structure enum
  enum CausalType {
    TIMELIKE = 0,
    SPACELIKE,
    LIGHTLIKE
  };
  FourVector();
  FourVector(const FourVector& other);
  FourVector(const double t, const double x, const double y, const double z);
  FourVector(const double t, const ThreeVector& v);

  //! Copy-assignment operator
  FourVector& operator=(const FourVector& other);

  //! Add a vector to this one
  FourVector& operator+=(const FourVector& rhs);

  //! Subtract a vector from this one
  FourVector& operator-=(const FourVector& rhs);

  //! Multiply components of this vector by a constant
  FourVector& operator*=(const double rhs);
  
  //! Divide components of this vector by a constant
  FourVector& operator/=(const double rhs);

  //! return the interval of the vector
  double interval() const;

  //! boost the vector along the z-axis [1]
  int boost_z(const double velocity);

  //! return the causal type of the vector
  CausalType getCausalType() const;

  //! get t, x, y, z components of vector
  double getT() const {return t_;}
  const ThreeVector& getThreeVector() const {return x_;}
  double getX() const {return x_.getX();}
  double getY() const {return x_.getY();}
  double getZ() const {return x_.getZ();}

  //! set t, x, y, z components of vector
  void setT(const double t); 
  void setThreeVector(const ThreeVector& v);
  void setX(const double x);
  void setY(const double y);
  void setZ(const double z);

private:
  //! recompute interval whenever components change
  void compute_interval();
private:
  //! member variables
  double t_;
  ThreeVector x_;
  double s_; // current interval
};

//! Create a FourVector with components
FourVector* createFourVector(const double t, const double x, const double y,
                             const double z);

//! Destroy a FourVector instance, nulling the supplied pointer
void destroyFourVector(FourVector *&p);

FourVector operator+(const FourVector& lhs, const FourVector& rhs);
FourVector operator-(const FourVector& lhs, const FourVector& rhs);
FourVector operator*(const FourVector& lhs, const double rhs);
FourVector operator*(const double lhs, const FourVector& rhs);
FourVector operator/(const FourVector& lhs, const double rhs);

#endif //FOURVECTOR_HH
