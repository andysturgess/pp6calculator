//! \file   PP6Math_d1.hpp
//! \author Andy Sturgess
//! \brief  Declarations for pp6calculator - day one

#include <complex>

#ifndef PP6CALCULATOR_PP6MATH_D1_HH
#define PP6CALCULATOR_PP6MATH_D1_HH

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


#endif // PP6CALCULATOR_PP6MATH_D1_HH
