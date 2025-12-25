#include <vector>

class Solution {
 public:
  bool hasTrailingZeros(std::vector<int>& nums) {
    int evens{0};
    for (int num : nums) {
      if (num % 2 == 0) {
        if (++evens == 2) return true;
      }
    }
    return false;
  }
};
