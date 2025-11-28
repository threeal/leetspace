#include <vector>

class Solution {
 public:
  int maxSum(std::vector<int>& nums) {
    bool exists[101]{false}, positiveExists{false};
    int maxNegative{-101}, sumPositives{0};
    for (const int num : nums) {
      if (num >= 0) {
        positiveExists = true;
        if (!exists[num]) {
          exists[num] = true;
          sumPositives += num;
        }
      } else {
        if (num >= maxNegative) maxNegative = num;
      }
    }

    return positiveExists ? sumPositives : maxNegative;
  }
};
