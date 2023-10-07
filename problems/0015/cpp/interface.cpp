#include <interface.hpp>
#include <vector>

using namespace std;

#include "solution.cpp"

template <>
vector<vector<int>> solution_cpp(const vector<int>& nums) {
  auto nums_copy = nums;
  return Solution().threeSum(nums_copy);
}
