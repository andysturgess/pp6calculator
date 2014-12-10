#ifndef ENERGYCUT_HPP
#define ENERGYCUT_HPP

#include "Cut.hpp"

class EnergyCut : public Cut{
public:

  EnergyCut(std::string CutType, double firstVal);
  EnergyCut(std::string CutType, double firstVal, double secondVal);

  virtual ~EnergyCut();

  virtual bool select(const Particle& input) const;
  virtual std::vector<Particle> select (const std::vector<Particle>& inputVec) const;

private:

  const std::string CutType_;
  const double firstVal_;
  const double secondVal_;

};

#endif // ENERGYCUT_HPP
