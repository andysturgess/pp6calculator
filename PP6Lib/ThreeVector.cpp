// ThreeVector.cpp : Implementing ThreeVector

#include "ThreeVector.hpp"
#include <cmath>
#include <iostream>
#include <sstream>

//! Function to calculate the length of the threevector
//! put at start of input so I dont confuse myself...
//! calculate the length for each type of three-vector!

void ThreeVector::three_length(){
  l_ = sqrt(x_*x_ + y_*y_ + z_*z_);
}

//! Default threevector (i.e null points)

ThreeVector::ThreeVector() : x_(0.0), y_(0.0), z_(0.0){
  three_length(); 
}

//! Copy constructor three-vector, sets 'other' vector
//! to have same values as this vector.
 
ThreeVector::ThreeVector(const ThreeVector& other)
  : x_(other.getX()), y_(other.getY()), z_(other.getZ()){
  three_length();
}

//! Threevector with an initialiser list; this sets constant
//! values within the class.

ThreeVector::ThreeVector(const double x, const double y, 
			 const double z) 
  : x_(x), y_(y), z_(z)   {
  three_length();
}

//! Define operator += for adding threevectors, uses the getI
//! functions; this takes the X,Y,Z values of rhs threevector
//! then computers the length and returns the values.


ThreeVector& ThreeVector::operator+=(const ThreeVector& rhs){
  x_ += rhs.getX();
  y_ += rhs.getY();
  z_ += rhs.getZ();
  three_length();
  return *this;
}

//! Define operator -= for subtracting threevectors.

ThreeVector& ThreeVector::operator-=(const ThreeVector& rhs){
  x_ -= rhs.getX();
  y_ -= rhs.getY();
  z_ -= rhs.getZ();
  three_length();
  return *this;
}

//! Define operator *= for multiplying threevector 
//! elements by a constant number.

ThreeVector& ThreeVector::operator*=(const double rhs){
  x_ *= rhs;
  y_ *= rhs;
  z_ *= rhs;
  three_length();
  return *this;
}

//! Define operator *= for multiplying threevector 
//! elements, by the elements of another threevector
//! (like scalar product!).

ThreeVector& ThreeVector::operator*=(const ThreeVector& rhs){
  x_ *= rhs.getX();
  y_ *= rhs.getY();
  z_ *= rhs.getZ();
  three_length();
  return *this;
}

//! Define operator /= for dividing threevector 
//! elements by a constant number.

ThreeVector& ThreeVector::operator/=(const double rhs){
  x_ /= rhs;
  y_ /= rhs;
  z_ /= rhs;
  three_length();
  return *this;
}

//! Define operator /= for dividing threevector elements,
//! by the elements of another threevector (like scalar 
//! product, but dotting with reciprocal!).

ThreeVector& ThreeVector::operator/=(const ThreeVector& rhs){
  x_ /= rhs.getX();
  y_ /= rhs.getY();
  z_ /= rhs.getZ();
  three_length();
  return *this;
}

//! returns the length of the threevector
double ThreeVector::length() const{
  return l_;
}

//! returns the length of the threevector, with x set.
void ThreeVector::setX(const double x){
  x_ = x;
  three_length();
}

//! returns the length of the threevector, with y set.
void ThreeVector::setY(const double y){
  y_ = y;
  three_length();
}

//! returns the length of the threevector, with z set.
void ThreeVector::setZ(const double z){
  z_ = z;
  three_length();
}

//! Free operator = adds two three-vectors together!
ThreeVector operator+(const ThreeVector& lhs, const ThreeVector& rhs){
  ThreeVector temp(lhs);
  temp += rhs;
  return temp;
}

//! Free operator = subtracts three-vectors 
ThreeVector operator-(const ThreeVector& lhs, const ThreeVector& rhs){
  ThreeVector temp(lhs);
  temp -= rhs;
  return temp;
}

//! Free operator = multiplies a three-vector with a constant(rhs)
ThreeVector operator*(const ThreeVector& lhs, const double rhs){
  ThreeVector temp(lhs);
  temp *= rhs;
  return temp;
}

//! Free operator = multiplies a three-vector with a constant(lhs)
ThreeVector operator*(const double lhs, const ThreeVector& rhs){
  ThreeVector temp(rhs);
  temp *= lhs;
  return temp;
}

//! Free operator = multiplies a three-vector with another!
ThreeVector operator*(const ThreeVector& lhs, const ThreeVector& rhs){
  ThreeVector temp(rhs);
  temp *= lhs;
  return temp;
}

//! Free operator = divides a three-vector with a constant(rhs)
ThreeVector operator/(const ThreeVector& lhs, const double rhs){
  ThreeVector temp(lhs);
  temp /= rhs;
  return temp;
}

//! Free operator = divides a three-vector with a constant
ThreeVector operator/(const ThreeVector& lhs, const ThreeVector& rhs){
  ThreeVector temp(lhs);
  temp /= rhs;
  return temp;
}

//! Taken from Ben Morgan's example; allows us to use instream
//! and outstream operators; very important for pp6!

std::istream& operator>>(std::istream& in, ThreeVector& vec){
  std::string dummy;
  double x(0), y(0), z(0);
  in >> dummy >> x >> dummy >> y >> dummy >> z >> dummy;
  vec.setX(x);
  vec.setY(y);
  vec.setZ(z);
  return in;
}

std::ostream& operator<<(std::ostream& out, const ThreeVector& vec){
  out << "( " << vec.getX() << " , " << vec.getY() << " , " << vec.getZ() << " )";
  return out;
}
