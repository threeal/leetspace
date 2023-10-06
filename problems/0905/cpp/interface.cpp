#include <interface.hpp>
#include <list>
#include <vector>

using namespace std;

#include "solution.cpp"

template <>
vector<int> solution_cpp(const vector<int>& nums) {
  auto nums_copy = nums;
  return Solution().sortArrayByParity(nums_copy);
}
