#include <algorithm>
#include <vector>

class Solution {
 public:
  int minCapability(std::vector<int>& nums, int k) {
    int low{0}, high{*std::max_element(nums.begin(), nums.end())};
    while (low < high) {
      const int mid{low + (high - low) / 2};

      int count{0};
      for (std::size_t i{0}; i < nums.size(); ++i) {
        if (nums[i] <= mid) {
          if (++count == k) break;
          ++i;
        }
      }

      if (count != k) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};
