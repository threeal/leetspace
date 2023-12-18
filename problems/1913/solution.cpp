#include <vector>

class Solution {
 public:
  int maxProductDifference(std::vector<int>& nums) {
    // Sort the first 4 elements.
    std::sort(nums.begin(), nums.begin() + 4);

    // Store the 2 largest elements in `a` and `b`.
    // `b` should be larger than `a`.
    int a = nums[2];
    int b = nums[3];

    // Store the 2 smallest elements in `c` and `d`.
    // `d` should be smaller than `c`.
    int c = nums[1];
    int d = nums[0];

    // Iterate over the rest of the elements to update
    // the largest and smallest elements.
    for (std::size_t i = 4; i < nums.size(); ++i) {
      if (nums[i] > a) {
        if (nums[i] > b) {
          a = b;
          b = nums[i];
        } else {
          a = nums[i];
        }
      } else if (nums[i] < c) {
        if (nums[i] < d) {
          c = d;
          d = nums[i];
        } else {
          c = nums[i];
        }
      }
    }

    // Calculate the maximum product difference.
    return (a * b) - (c * d);
  }
};
