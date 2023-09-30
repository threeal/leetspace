#include <vector>

using namespace std;

#include "solution.cpp"

bool solution_cpp(const std::vector<int>& nums) {
  Solution solution;
  auto nums_copy = nums;
  return solution.find132pattern(nums_copy);
}
