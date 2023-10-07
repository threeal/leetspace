#include "interface.hpp"

#include "solution.cpp"

template <>
int solution_cpp(const int& n) {
  return Solution().integerBreak(n);
}
