#include <interface.hpp>
#include <vector>

using namespace std;

#include "solution.cpp"

template <>
vector<int> solution_cpp(const vector<int>& nums, const int& target) {
  auto nums_copy = nums;
  return Solution().twoSum(nums_copy, target);
}
