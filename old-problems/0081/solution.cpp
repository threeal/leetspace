#include <vector>

class Solution {
 public:
  bool search(std::vector<int>& nums, int target) {
    if (nums.front() == target || nums.back() == target) return true;

    std::size_t front{0}, back{nums.size() - 1};
    while (nums[front] == nums.front() && nums[back] == nums.back() &&
           front < back) {
      ++front;
      --back;
    }

    if (front > back) return false;

    if (target <= nums[back]) {
      if (target == nums[back]) return true;

      std::size_t low{front}, high{back};
      while (low < high) {
        const std::size_t mid{low + (high - low) / 2};
        if (nums[mid] > nums[back] || nums[mid] < target) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }

      return nums[low] == target;
    } else if (target >= nums[front]) {
      if (target == nums[front]) return true;

      std::size_t low{front}, high{back};
      while (low < high) {
        const std::size_t mid{high - (high - low) / 2};
        if (nums[mid] < nums[front] || nums[mid] > target) {
          high = mid - 1;
        } else {
          low = mid;
        }
      }

      return nums[low] == target;
    }

    return false;
  }
};
