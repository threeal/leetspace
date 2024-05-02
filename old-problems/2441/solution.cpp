#include <vector>

class Solution {
 public:
  int findMaxK(std::vector<int>& nums) {
    std::vector<bool> exists(1001, false);
    for (const auto num : nums) {
      if (num < 0) exists[-num] = true;
    }

    int largestNum{-1};
    for (const auto num : nums) {
      if (num > 0 && exists[num] && largestNum < num) largestNum = num;
    }

    return largestNum;
  }
};
