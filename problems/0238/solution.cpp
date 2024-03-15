#include <vector>

class Solution {
 public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int zeros = 0;
    int product = 1;
    for (const auto num : nums) {
      if (num == 0) {
        ++zeros;
      } else {
        product *= num;
      }
    }

    switch (zeros) {
      case 0:
        for (auto& num : nums) {
          num = product / num;
        }
        break;

      case 1:
        for (auto& num : nums) {
          if (num == 0) {
            num = product;
          } else {
            num = 0;
          }
        }
        break;

      default:
        for (auto& num : nums) {
          num = 0;
        }
    }

    return nums;
  }
};
