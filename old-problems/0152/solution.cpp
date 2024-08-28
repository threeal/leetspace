#include <limits>
#include <vector>

class Solution {
 public:
  int maxProduct(std::vector<int>& nums) {
    int max{std::numeric_limits<int>::min()};

    int r = nums.size() - 1;
    while (r >= 0) {
      while (r >= 0 && nums[r] == 0) {
        if (max < 0) max = 0;
        --r;
      }
      if (r < 0) break;

      int product{1};
      int l{r};
      while (l >= 0 && nums[l] != 0) {
        product *= nums[l];
        --l;
      }

      if (product > 0) {
        if (product > max) max = product;
      } else {
        int tempProduct{product};
        for (int i = l + 1; i < r && product < 0; ++i) {
          product /= nums[i];
        }
        if (product > max) max = product;

        for (int i = r; i > l + 1 && tempProduct < 0; --i) {
          tempProduct /= nums[i];
        }
        if (tempProduct > max) max = tempProduct;
      }

      r = l;
    }

    return max;
  }
};
