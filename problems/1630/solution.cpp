// The solution can be done simply by slicing the array, sorting it,
// and then iterating through it to check if each element has the same difference.

#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, std::vector<int>& l, std::vector<int>& r) {
    // Construct the result array, it defaults to true.
    const auto n = std::min(l.size(), r.size());
    std::vector<bool> isArithmetics(n, true);

    // Iterating over the given subarrays.
    for (std::size_t i = 0; i < n; ++i) {
      // Subarray with a size of 2 or less is always considered arithmetic.
      if (r[i] - l[i] <= 1) continue;

      // Slice the array with the given left and right range.
      std::vector<int> subnums(nums.begin() + l[i], nums.begin() + r[i] + 1);

      // Sort the subarray.
      std::sort(subnums.begin(), subnums.end());

      // Check if the difference between each element is the same.
      const auto diff = subnums[1] - subnums[0];
      for (std::size_t j = 2; j < subnums.size(); ++j) {
        if (subnums[j] - subnums[j - 1] != diff) {
          isArithmetics[i] = false;
          break;
        }
      }
    }

    return isArithmetics;
  }
};
