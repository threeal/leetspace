#include <vector>

class Solution {
 public:
  int maximumScore(std::vector<int>& nums, int k) {
    int left = k;
    int right = k;

    int minNum = nums[k];
    int maxScore = minNum;

    const int n = nums.size();
    while (left > 0 || right < n - 1) {
      if (left == 0 || (right < n - 1 && nums[right + 1] > nums[left - 1])) {
        ++right;
        minNum = std::min(minNum, nums[right]);
      } else {
        --left;
        minNum = std::min(minNum, nums[left]);
      }

      maxScore = std::max(maxScore, minNum * (right - left + 1));
    }

    return maxScore;
  }
};
