//! \file PP6Math.hpp
//! \author Andy Sturgess
//! \brief Declarations for pp6calculator - day one, day two

#include<utility>
#include<complex>

#ifndef PP6CALCULATOR_PP6MATH_HH
#define PP6CALCULATOR_PP6MATH_HH

// Day One Declarations
// ----------------------------------------------------------------
// Arithmetic
// ----------------------------------------------------------------

double add(double a,double b);
double subtract(double a, double b);
double multiply(double a,double b);
double divide(double a, double b);

// Solvers
// ---------------------------------------------------------------

double intercept(double a, double b, double c, double d);
std::pair<std::complex<double>,std::complex<double> > quadratic(std::complex<double> m,std::complex<double> n, std::complex<double> o, bool& pos, bool& neg);
double vectorlength3(double a, double b, double c);
double vectorlength4(double a, double b, double c, double d);
double invmass(double a, double b, double c, double d, double theta);

// Day two declarations
//----------------------------------------------------------------
double inputvalue();
void swap(double& a, double&b);
void Bubble(double array[]);
void SPECTRUM();

// Day three declarations
//-----------------------------------------------------------------
struct FourVec{
  double x;
  double y;
  double z;
  double t;
};

enum InvariantSign{
  SPACELIKE,
  TIMELIKE,
  LIGHTLIKE,
  UNDEFINED
};

FourVec* createFourVec();
InvariantSign getInvariantSign(FourVec *q);
void destroyFourVec(FourVec *&q);
void fillFourVec(FourVec *q, double x, double y, double z, double t);
void evalboostz(FourVec *q, double v);
void opinterval(FourVec *q);
void boostalongz(double x, double y, double& z, double& t, double v);
void boostz(FourVec q, double v);
double invint(FourVec q);
#endif // PP6CALCULATOR_PP6MATH_HH
