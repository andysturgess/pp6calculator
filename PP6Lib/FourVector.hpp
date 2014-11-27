//! \file   FourVector.hpp
//! \author Andy Sturgess
//! \brief Declarations for FourVector

#include <iostream>

class FourVector {
public:
  enum CausalType{
    TIMEL,
    SPACEL,
    LIGHTL
  };

public:
  //ctors
  FourVector(): x(0) {}
  FourVector(double val) : x(val){}
  FourVector(const double x_, const double y_,
	     const double z_, const double t_);
  ~FourVector(){}

  FourVector& operator+=(const FourVector& rhs){
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    t += rhs.t;
    return *this;
  }

  FourVector& operator-=(const FourVector& rhs){
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    t += rhs.t;
    return *this;
  }

  FourVector& operator*=(const FourVector& rhs){
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    t *= rhs.t;
    return *this;
  }
  
  FourVector& operator/=(const FourVector& rhs){
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    t /= rhs.t;
    return *this;
  }

  FourVector& operator=(const FourVector& rhs){
    if (&rhs != this) {
      x = rhs.x;
      y = rhs.y;
      z = rhs.z;
      t = rhs.t;
    } 
    return *this;
  }

  
  //member functions
  double getX(), getY(), getZ(), getT();
  void setX(double value), setY(double value), setZ(double value);
  void setT(double value);
  double interval() const;
  void boost_z(double v);
  CausalType getCausalType(FourVector q);

private:
  //member variables
  double x;
  double y;
  double z;
  double a;
  double t;
};

FourVector operator+(const FourVector& lhs, const FourVector& rhs);
FourVector operator-(const FourVector& lhs, const FourVector& rhs);
FourVector operator*(const FourVector& lhs, const FourVector& rhs);
FourVector operator/(const FourVector& lhs, const FourVector& rhs);
FourVector operator==(const FourVector& lhs, const FourVector& rhs);

FourVector

