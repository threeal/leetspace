#include <algorithm>
#include <functional>
#include <interface.hpp>
#include <vector>

using namespace std;

#include "solution.cpp"

template <>
int solution_cpp(const std::vector<int>& cost) {
  auto cost_copy = cost;
  return Solution().minCostClimbingStairs(cost_copy);
}
