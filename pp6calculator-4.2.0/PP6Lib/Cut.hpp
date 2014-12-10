#ifndef PP6CUT_HPP
#define PP6CUT_HPP

#include <iostream>
#include <vector>

class Particle;

class Cut {
public: 
  virtual ~Cut() {std::cout << "This action is Cut" << std::endl;}

  virtual bool select(const Particle& input) const = 0;
  virtual std::vector<Particle> select(const std::vector<Particle>& inputVec) const = 0;
};

#endif // PP6CUT_HPP
