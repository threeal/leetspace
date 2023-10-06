#include <interface.hpp>
#include <unordered_set>
#include <vector>

using namespace std;

#include "solution.cpp"

template <>
vector<int> solution_cpp(const vector<int>& nums) {
  auto nums_copy = nums;
  const auto k = Solution().removeDuplicates(nums_copy);
  nums_copy.resize(k);
  return nums_copy;
}
