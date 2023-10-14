#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#include "solution.cpp"

vector<vector<int>> solution_cpp(const vector<int>& nums) {
  auto nums_copy = nums;
  auto res = Solution().threeSum(nums_copy);
  sort(res.begin(), res.end());
  return res;
}
