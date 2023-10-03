#include <vector>

using namespace std;

#include "solution.cpp"

int solution_cpp(const std::vector<int>& nums) {
  Solution solution;
  auto nums_copy = nums;
  return solution.numIdenticalPairs(nums_copy);
}
