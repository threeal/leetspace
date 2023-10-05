#include <interface.hpp>
#include <vector>

using namespace std;

#include "solution.cpp"

template <>
vector<int> solution_cpp(const vector<int>& nums, const int& val) {
  auto nums_copy = nums;
  const auto k = Solution().removeElement(nums_copy, val);
  nums_copy.resize(k);
  return nums_copy;
}
