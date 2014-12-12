#ifndef NUMERIC_CUT_HPP
#define NUMERIC_CUT_HPP

#include "Cut.hpp"

class NumericCut : public Cut{
public:

  NumericCut(std::string CutType, double firstVal);
  NumericCut(std::string CutType, double firstVal, double secondVal);
  virtual ~NumericCut();
  virtual bool select(const Particle& input) const;
  virtual std::vector<Particle> select(const std::vector<Particle>& inputVec) const;

private:

  const std::string CutType_;
  const double firstVal_;
  const double secondVal_;

};

#endif //NUMERIC_CUT_HPP

