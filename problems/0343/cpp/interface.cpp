#include "interface.hpp"

#include <vector>

using namespace std;

#include "solution.cpp"

template <>
int solution_cpp(const int& n) {
  return Solution().integerBreak(n);
}
