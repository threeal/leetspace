// In this solution, we calculate backward, starting from the last
// multiplication and working towards the first.
//
// Since we're calculating backward, we only need a one-dimensional array to
// store the previous multiplication results, which reduces memory usage.
//
// In each multiplication calculation, we determine the left and right indices
// of the subarray we're going to consider and update the current calculation
// with the maximum value of either the left or right value multiplied by the
// current multiplier, combined with the corresponding multiplication from the
// previous calculation.

#include <cstdlib>
#include <vector>

class Solution {
 public:
  int maximumScore(std::vector<int>& nums, std::vector<int>& multipliers) {
    // We only need a one-dimensional array to store the memoization.
    // The extra element at the end (+ 1) is for handling the multiplication on
    // the first calculation.
    std::vector<int> memo(multipliers.size() + 1, 0);

    // Do calculation from the last multiplication to the first.
    for (int i = multipliers.size() - 1; i >= 0; --i) {
      // Determine the left and right indices of the subarray.
      for (int l = 0, r = nums.size() - i - 1; l <= i; ++l, ++r) {
        // Update the memoization with the maximum value considering both left
        // and right options.
        memo[l] = std::max(
            nums[l] * multipliers[i] + memo[l + 1],
            nums[r] * multipliers[i] + memo[l]);
      }
    }

    // Return the result of the last calculation.
    return memo[0];
  }
};
