#include <vector>

using namespace std;

#include "solution.cpp"

std::vector<int> solution_cpp(const vector<int>& nums, const int& target) {
  auto nums_copy = nums;
  return Solution().searchRange(nums_copy, target);
}
