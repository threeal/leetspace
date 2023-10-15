#include <functional>
#include <interface.hpp>

using namespace std;

#include "solution.cpp"

template <>
int solution_cpp(const int& steps, const int& arrLen) {
  return Solution().numWays(steps, arrLen);
}
