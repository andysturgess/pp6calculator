// ThreeVector.cpp : Implementing ThreeVector

#include <cmath>
#include <iostream>
#include "ThreeVector.hpp"

ThreeVector::ThreeVector(const double x, const double y, 
			 const double z) 
  : x_(x), y_(y), z_(z)
    
{compute_length();}

ThreeVector& ThreeVector::operator+=(const ThreeVector& rhs){
  x_ += rhs.getX();
  y_ += rhs.getY();
  z_ += rhs.getZ();
  compute_length();
  return *this;
}

ThreeVector& ThreeVector::operator-=(const ThreeVector& rhs){
  x_ -= rhs.getX();
  y_ -= rhs.getY();
  z_ -= rhs.getZ();
  compute_length();
  return *this;
}

ThreeVector& ThreeVector::operator*=(const double rhs){
  x_ *= rhs;
  y_ *= rhs;
  z_ *= rhs;
  compute_length();
  return *this;
}

ThreeVector& ThreeVector::operator/=(const double rhs){
  x_ /= rhs;
  y_ /= rhs;
  z_ /= rhs;
  compute_length();
  return *this;
}

double ThreeVector::length() const{
  return l_;
}

void ThreeVector::setX(const double x){
  x_ = x;
  compute_length();
}

void ThreeVector::setY(const double y){
  y_ = y;
  compute_length();
}

void ThreeVector::setZ(const double z){
  z_ = z;
  compute_length();
}

ThreeVector operator+(const ThreeVector& lhs, const ThreeVector& rhs){
  ThreeVector temp(lhs);
  temp += rhs;
  return temp;
}

ThreeVector operator-(const ThreeVector& lhs, const ThreeVector& rhs){
  ThreeVector temp(lhs);
  temp -= rhs;
  return temp;
}

ThreeVector operator*(const ThreeVector& lhs, const double rhs){
  ThreeVector temp(lhs);
  temp *= rhs;
  return temp;
}

ThreeVector operator*(const double lhs, const ThreeVector& rhs){
  ThreeVector temp(rhs);
  temp *= lhs;
  return temp;
}

ThreeVector operator/(const ThreeVector& lhs, const double rhs){
  ThreeVector temp(lhs);
  temp /= rhs;
  return temp;
}

void ThreeVector::compute_length(){
  l_ = sqrt(x_*x_ + y_*y_ + z_*z_);
}

