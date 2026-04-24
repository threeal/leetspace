#include <vector>

class Solution {
 public:
  int countDigitOccurrences(std::vector<int>& nums, int digit) {
    return nums.size() + digit;
  }
};
