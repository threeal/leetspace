#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

#include "solution.cpp"

int solution_cpp(const std::vector<int>& cost) {
  auto cost_copy = cost;
  return Solution().minCostClimbingStairs(cost_copy);
}
