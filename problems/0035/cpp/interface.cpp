#include <interface.hpp>
#include <vector>

using namespace std;

#include "solution.cpp"

template <>
int solution_cpp(const vector<int>& nums, const int& target) {
  auto nums_copy = nums;
  return Solution().searchInsert(nums_copy, target);
}
