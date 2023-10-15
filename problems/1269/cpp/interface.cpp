#include <algorithm>
#include <functional>
#include <interface.hpp>
#include <vector>

using namespace std;

#include "solution.cpp"

template <>
int solution_cpp(const int& steps, const int& arrLen) {
  return Solution().numWays(steps, arrLen);
}
