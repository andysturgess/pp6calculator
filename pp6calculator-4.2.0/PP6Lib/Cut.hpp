//!   File : Cut.hpp
//!   Auth : Andy Sturgess
//!   Descr: Cut ex1- day5

#ifndef CUT_EX1_DAY5_HPP
#define CUT_EX1_DAY5_HPP

#include<vector>
#include<iostream>

class Cut{
public:
  virtual ~Cut(){
    std::cout << "Cut::~Cut(" << this << ")" << std::endl;
  }
  
  virtual bool select(const Particle& input) = 0;
  virtual std::vector<Particle> select(const std::vector<Particle>& input) = 0 
 

};

#endif // CUT_EX1_DAY5_HPP
  
