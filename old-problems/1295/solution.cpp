#include <vector>

class Solution {
 public:
  int findNumbers(std::vector<int>& nums) {
    int count{0};
    for (const int num : nums) {
      if ((num >= 10 && num < 100) ||
          (num >= 1000 && num < 10000) ||
          num == 100000) {
        ++count;
      }
    }
    return count;
  }
};
