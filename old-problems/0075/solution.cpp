#include <vector>

class Solution {
 public:
  void sortColors(std::vector<int>& nums) {
    int zero{0};
    int one{0};
    for (const auto num : nums) {
      switch (num) {
        case 0:
          ++zero;
          break;

        case 1:
          ++one;
          break;
      }
    }

    std::fill_n(nums.begin(), zero, 0);
    std::fill_n(nums.begin() + zero, one, 1);
    std::fill(nums.begin() + zero + one, nums.end(), 2);
  }
};
