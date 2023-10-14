#include <interface.hpp>
#include <vector>

using namespace std;

#include "solution.cpp"

template <>
int solution_cpp(const std::vector<int>& cost, const std::vector<int>& time) {
  auto cost_copy = cost;
  auto time_copy = time;
  return Solution().paintWalls(cost_copy, time_copy);
}
