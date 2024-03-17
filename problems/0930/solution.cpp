#include <unordered_map>
#include <vector>

class Solution {
 public:
  int numSubarraysWithSum(std::vector<int>& nums, int goal) {
    std::unordered_map<int, int> counts;
    counts[0] = 1;

    int sum = 0;
    int subarrays = 0;

    for (int num : nums) {
      sum += num;
      subarrays += counts[sum - goal];
      ++counts[sum];
    }

    return subarrays;
  }
};
