#include <vector>

class Solution {
 public:
  int minimumOperations(std::vector<int>& nums) {
    std::vector<bool> exists(101, false);
    exists[0] = true;

    int uniques{0};
    for (const int num : nums) {
      if (!exists[num]) {
        exists[num] = true;
        ++uniques;
      }
    }

    return uniques;
  }
};
