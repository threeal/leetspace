#include <algorithm>
#include <vector>

class Solution {
 public:
  int smallestDistancePair(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());

    int low{0};
    int high{nums.back() - nums.front()};
    while (low < high) {
      int mid{low + (high - low) / 2};
      int count{0};
      for (std::size_t l{0}, r{1}; r < nums.size(); ++r) {
        while (l < r && nums[r] - nums[l] > mid) ++l;
        count += r - l;
      }

      if (count < k) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }

    return low;
  }
};
