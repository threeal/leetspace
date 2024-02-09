#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
    const int n = nums.size();
    std::sort(nums.begin(), nums.end());

    std::vector<int> prevOf(n, -1);
    std::vector<int> countOf(n, 1);

    int candidate = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (nums[i] % nums[j] == 0 && countOf[j] + 1 > countOf[i]) {
          prevOf[i] = j;
          countOf[i] = countOf[j] + 1;
        }
      }

      if (countOf[i] > countOf[candidate]) {
        candidate = i;
      }
    }

    std::vector<int> output{};
    output.reserve(countOf[candidate]);
    for (int i = candidate; i >= 0; i = prevOf[i]) {
      output.push_back(nums[i]);
    }

    return output;
  }
};
