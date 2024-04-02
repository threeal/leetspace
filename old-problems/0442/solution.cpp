#include <cstdlib>
#include <vector>

class Solution {
 public:
  std::vector<int> findDuplicates(std::vector<int>& nums) {
    std::vector<int> output;

    // Negates the numbers to track duplicates.
    for (const auto num : nums) {
      if (nums[std::abs(num) - 1] > 0) {
        nums[std::abs(num) - 1] *= -1;
      } else {
        output.push_back(std::abs(num));
      }
    }

    return output;
  }
};
