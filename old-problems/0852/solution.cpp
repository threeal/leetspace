#include <vector>

class Solution {
 public:
  int peakIndexInMountainArray(std::vector<int>& arr) {
    std::size_t low{0}, high{arr.size() - 2};
    while (low < high) {
      const std::size_t mid{low + (high - low) / 2};
      if (arr[mid] < arr[mid + 1]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};
