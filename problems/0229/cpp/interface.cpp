#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

#include "solution.cpp"

vector<int> solution_cpp(vector<int> nums) {
  auto res = Solution().majorityElement(nums);
  sort(res.begin(), res.end());
  return res;
}
