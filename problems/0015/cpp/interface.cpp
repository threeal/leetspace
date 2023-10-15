#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#include "solution.cpp"

vector<vector<int>> solution_cpp(vector<int> nums) {
  auto res = Solution().threeSum(nums);
  sort(res.begin(), res.end());
  return res;
}
