#include <vector>

class Solution {
 public:
  int countDigitOccurrences(std::vector<int>& nums, int digit) {
    int count{0};
    for (int num : nums) {
      while (num != 0) {
        if (num % 10 == digit) ++count;
        num /= 10;
      }
    }
    return count;
  }
};
