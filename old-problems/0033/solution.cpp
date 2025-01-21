#include <vector>

class Solution {
 public:
  int search(std::vector<int>& nums, int target) {
    if (target <= nums.back()) {
      if (target == nums.back()) return nums.size() - 1;

      std::size_t low{0}, high{nums.size() - 1};
      while (low < high) {
        const std::size_t mid{low + (high - low) / 2};
        if (nums[mid] > nums.back() || nums[mid] < target) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }

      return nums[low] == target ? low : -1;
    } else if (target >= nums.front()) {
      if (target == nums.front()) return 0;

      std::size_t low{0}, high{nums.size() - 1};
      while (low < high) {
        const std::size_t mid{high - (high - low) / 2};
        if (nums[mid] < nums.front() || nums[mid] > target) {
          high = mid - 1;
        } else {
          low = mid;
        }
      }

      return nums[low] == target ? low : -1;
    } else {
      return -1;
    }
  }
};
