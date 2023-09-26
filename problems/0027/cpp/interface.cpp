#include <vector>

using namespace std;

#include "solution.cpp"

vector<int> solution_cpp(vector<int> nums, int val) {
  const auto k = Solution().removeElement(nums, val);
  nums.resize(k);
  return nums;
}
