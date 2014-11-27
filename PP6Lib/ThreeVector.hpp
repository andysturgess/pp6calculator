//! file     ThreeVector.hpp
//! Author   Andy Sturgess
//! Descr.   Declaration of the three vector class

#ifndef THREEVECTOR_HH
#define THREEVECTOR_HH

#include <iosfwd>
#include <string>

class ThreeVector{
public:
  //constructors - Default
  ThreeVector();

  //constructor - This has values
  ThreeVector(const double x_, const double y_, const double z_);
  
  //op overloading - equals;
 
  //op overloading - adding three vector to this
  ThreeVector& operator+=(const ThreeVector& rhs){
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
  }

  //op overloading - subtract a three vector from this
  ThreeVector& operator-=(const ThreeVector& rhs){
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
  }
  
  //op overloading - multiply vector elements;
  ThreeVector& operator*=(const ThreeVector& rhs){
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    return *this;
  }

  //op overloading - divide vector elements;
  ThreeVector& operator/=(const ThreeVector&  rhs){
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    return *this;
  }

  ThreeVector& operator=(const ThreeVector& rhs){
    if(&rhs != this){
      x = rhs.x;
      y = rhs.y;
      z = rhs.z;
    }
    return *this;
  }
  

  //Member Functions
  
  //getting length of threevector
  double length();
  
  //getting/setting the components of the vector
  double getX();
  double getY();
  double getZ();
  void setX(double value);
  void setY(double value);
  void setZ(double value);
  double three_length();

private:
  double x;
  double y;
  double z;
  double l;  // the current length!
};

ThreeVector operator+(const ThreeVector& lhs, const ThreeVector& rhs);
ThreeVector operator-(const ThreeVector& lhs, const ThreeVector& rhs);
ThreeVector operator*(const ThreeVector& lhs, const ThreeVector& rhs);
ThreeVector operator/(const ThreeVector& lhs, const ThreeVector& rhs);
double ScalarProd( ThreeVector &a,  ThreeVector &b);

#endif // THREEVECTOR_HH
