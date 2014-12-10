#ifndef MASSCUT_HPP
#define MASSCUT_HPP

#include "Cut.hpp"

class MassCut : public Cut{
public:

  MassCut(std::string CutType, double firstVal);
  MassCut(std::string CutType, double firstVal, double secondVal);
  virtual ~MassCut();
  virtual bool select(const Particle& input) const;
  virtual std::vector<Particle> select(const std::vector<Particle>& inputVec) const;

private:

  const std::string CutType_;
  const double firstVal_;
  const double secondVal_;

};

#endif //MASSCUT_HPP
