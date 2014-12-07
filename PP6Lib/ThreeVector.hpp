//! file     ThreeVector.hpp
//! Author   Andy Sturgess
//! Descr.   Declaration of the three vector class

#ifndef THREEVECTOR_HH
#define THREEVECTOR_HH

#include <iosfwd>
#include <string>

class ThreeVector{
public:

  //! Default constructor
  ThreeVector();

  //! Copy constructor
  ThreeVector(const ThreeVector& other);
  
  //! Constructor with values
  ThreeVector(const double x, const double y, const double z);
  
  //! Add a vector
  ThreeVector& operator+=(const ThreeVector& rhs);

  //! Subtract a vector
  ThreeVector& operator-=(const ThreeVector& rhs);
  
  //! Multiply vector elements by a const
  ThreeVector& operator*=(const double rhs);

  //! Multiply a three vector!
  ThreeVector& operator*=(const ThreeVector& rhs);

  //! Divide vector elements by a const
  ThreeVector& operator/=(const double rhs);

  //! Divide a three vector!
  ThreeVector& operator/=(const ThreeVector& rhs);

  //! Length of this vector
  double length() const;

  //! get x, y, z components of vector; actually obtains our values
  //! using the initialiser list in .cpp file!
  double getX() const {return x_;}
  double getY() const {return y_;}
  double getZ() const {return z_;}

  //! set x, y, z components of vector
  void setX(const double x);
  void setY(const double y);
  void setZ(const double z);

private:
  //! place three length here; want to recalc the length if variables change!
  void three_length();
private:
  //! member variables
  double x_;
  double y_;
  double z_;
  double l_; // current length
};

//! Need to declare in and out streaming operators
//! Very important! else no match error for something like
//! cout << sum, where sum is a threevector; taken from
//! Ben Morgan's example!

std::istream& operator>>(std::istream& in, ThreeVector& vec);
std::ostream& operator<<(std::ostream& out, const ThreeVector& vec);


//! Free functions; they allow us to add,subtract,divide and multiply
//! our three vectors later on.

ThreeVector operator+(const ThreeVector& lhs, const ThreeVector& rhs);
ThreeVector operator-(const ThreeVector& lhs, const ThreeVector& rhs);
ThreeVector operator*(const ThreeVector& lhs, const double rhs);
ThreeVector operator*(const double lhs, const ThreeVector& rhs);
ThreeVector operator*(const ThreeVector& lhs, const ThreeVector& rhs);
ThreeVector operator/(const ThreeVector& lhs, const double rhs);
ThreeVector operator/(const ThreeVector& lhs, const ThreeVector& rhs);

#endif // THREEVECTOR_HH
