#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

#include "solution.cpp"

int solution_cpp(const vector<int>& nums) {
  auto nums_copy = nums;
  return Solution().minOperations(nums_copy);
}
