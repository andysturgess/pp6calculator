//! file     ThreeVector.hpp
//! Author   Andy Sturgess
//! Descr.   Declaration of the three vector class

#ifndef THREEVECTOR_HH
#define THREEVECTOR_HH

#include <iosfwd>
#include <string>

class ThreeVector{
public:

  //! Default ctor
  ThreeVector();
  
  //! Constructor with values
  ThreeVector(const double x, const double y, const double z);
  
  //! Add a vector
  ThreeVector& operator+=(const ThreeVector& rhs);

  //! Subtract a vector
  ThreeVector& operator-=(const ThreeVector& rhs);
  
  //! Multiply vector elements
  ThreeVector& operator*=(const double rhs);

  //! Divide vector elements
  ThreeVector& operator/=(const double rhs);

  //! Length of this vector
  double length() const;

   //! get t, x, y, z components of vector
  double getX() const {return x_;}
  double getY() const {return y_;}
  double getZ() const {return z_;}

  //! set t, x, y, z components of vector
  void setX(const double x);
  void setY(const double y);
  void setZ(const double z);

  private:
  //! recompute interval whenever components change
  void compute_length();
 private:
  //! member variables
  double x_;
  double y_;
  double z_;
  double l_; // current length
};

ThreeVector operator+(const ThreeVector& lhs, const ThreeVector& rhs);
ThreeVector operator-(const ThreeVector& lhs, const ThreeVector& rhs);
ThreeVector operator*(const ThreeVector& lhs, const double rhs);
ThreeVector operator*(const double lhs, const ThreeVector& rhs);
ThreeVector operator/(const ThreeVector& lhs, const double rhs);

double scalarProduct(const ThreeVector& a, const ThreeVector& b);

#endif // THREEVECTOR_HH
