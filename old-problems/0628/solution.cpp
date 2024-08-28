#include <algorithm>
#include <limits>
#include <vector>

class Solution {
 public:
  int maximumProduct(std::vector<int>& nums) {
    int min1{std::numeric_limits<int>::max()};
    int min2{std::numeric_limits<int>::max()};

    int max1{std::numeric_limits<int>::min()};
    int max2{std::numeric_limits<int>::min()};
    int max3{std::numeric_limits<int>::min()};

    for (const auto num : nums) {
      if (num > max3) {
        if (num > max1) {
          max3 = max2;
          max2 = max1;
          max1 = num;
        } else if (num > max2) {
          max3 = max2;
          max2 = num;
        } else {
          max3 = num;
        }
      }

      if (num < min2) {
        if (num < min1) {
          min2 = min1;
          min1 = num;
        } else {
          min2 = num;
        }
      }
    }

    return std::max(min1 * min2 * max1, max1 * max2 * max3);
  }
};
