#include <algorithm>
#include <interface.hpp>
#include <unordered_map>
#include <vector>

using namespace std;

#include "solution.cpp"

template <>
vector<int> solution_cpp(const std::vector<int>& nums) {
  auto nums_copy = nums;
  auto res = Solution().majorityElement(nums_copy);
  sort(res.begin(), res.end());
  return res;
}
