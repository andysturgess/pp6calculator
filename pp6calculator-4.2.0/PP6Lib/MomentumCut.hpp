#ifndef MOMENTUMCUT_HPP
#define MOMENTUMCUT_HPP

#include "Cut.hpp"

class MomentumCut : public Cut{
public:

  MomentumCut(std::string CutType, double firstVal);
  MomentumCut(std::string CutType, double firstVal, double secondVal);

  virtual ~MomentumCut();

  virtual bool select(const Particle& input) const;
  virtual std::vector<Particle> select (const std::vector<Particle>& inputVec) const;

private:

  const std::string CutType_;
  const double firstVal_;
  const double secondVal_;

};

#endif // MOMENTUMCUT_HPP
