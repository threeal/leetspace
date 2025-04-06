#include <vector>

class Solution {
 public:
  int minimumIndex(std::vector<int>& nums) {
    int majority{}, count{0};
    for (const auto num : nums) {
      if (count == 0) {
        majority = num;
        ++count;
      } else if (num == majority) {
        ++count;
      } else {
        --count;
      }
    }

    std::size_t majorityCount{0};
    for (const auto num : nums) {
      if (num == majority) ++majorityCount;
    }

    std::size_t leftCount{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      if (nums[i] == majority) {
        ++leftCount;
      }

      if (2 * leftCount > i + 1 &&
          2 * (majorityCount - leftCount) > nums.size() - i - 1) {
        return i;
      }
    }

    return -1;
  }
};
