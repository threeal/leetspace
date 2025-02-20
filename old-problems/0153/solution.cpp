#include <vector>

class Solution {
 public:
  int findMin(std::vector<int>& nums) {
    if (nums.front() < nums.back()) return nums.front();

    std::size_t low{0}, high{nums.size() - 1};
    while (low < high) {
      const std::size_t mid{low + (high - low) / 2};
      if (nums[mid] < nums.back()) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    return nums[low];
  }
};
