// ThreeVector.cpp : Implementing ThreeVector

#include <cmath>
#include <iostream>
#include "ThreeVector.hpp"

ThreeVector::ThreeVector(const double x_, const double y_, const double z_)
	      : x(x_), y(y_), z(z_)
{}

double ThreeVector::getX(){
  return x;
}

double ThreeVector::getY() {
  return y;
}

double ThreeVector::getZ() {
  return z;
}
void ThreeVector::setX(double value) {
  x = value;
}
void ThreeVector::setY(double value) { 
  y = value;
}
void ThreeVector::setZ(double value) {
  z = value;
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

ThreeVector operator*(const ThreeVector& lhs, const ThreeVector& rhs){
  ThreeVector temp(lhs);
  temp *= rhs;
  return temp;
}

ThreeVector operator/(const ThreeVector& lhs, const ThreeVector& rhs){
  ThreeVector temp(lhs);
  temp /= rhs;
  return temp;
}

double ThreeVector::three_length(){
  double s = x*x + y*y + z*z;
  return s;
}

double ScalarProd( ThreeVector &a,  ThreeVector &b){
  double product = a.getX() * b.getX() + a.getY() * b.getY() + a.getZ() * b.getZ();
  return product;
}
