#include <interface.hpp>
#include <unordered_map>
#include <vector>

using namespace std;

#include "solution.cpp"

template <>
vector<int> solution_cpp(const std::vector<int>& nums) {
  auto nums_copy = nums;
  return Solution().majorityElement(nums_copy);
}
