#include <vector>

using namespace std;

#include "solution.cpp"

int solution_cpp(const vector<int>& nums, const int& x) {
  auto nums_copy = nums;
  return Solution().minOperations(nums_copy, x);
}
