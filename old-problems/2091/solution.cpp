#include <utility>
#include <vector>

class Solution {
 public:
  int minimumDeletions(std::vector<int>& nums) {
    std::size_t min{0}, max{0};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] < nums[min]) {
        min = i;
      } else if (nums[i] > nums[max]) {
        max = i;
      }
    }

    if (min > max) std::swap(min, max);

    return std::min(
        std::min(max + 1, nums.size() - min),
        min + 1 + nums.size() - max);
  }
};
