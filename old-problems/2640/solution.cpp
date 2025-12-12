#include <vector>

class Solution {
 public:
  std::vector<long long> findPrefixScore(std::vector<int>& nums) {
    std::vector<long long> score(nums.size());

    int maxNum{0};
    long long sum{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      if (nums[i] >= maxNum) maxNum = nums[i];
      sum += nums[i] + maxNum;
      score[i] = sum;
    }

    return score;
  }
};
