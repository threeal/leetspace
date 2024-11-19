#include <algorithm>
#include <vector>

class Solution {
 public:
  int findLengthOfShortestSubarray(std::vector<int>& arr) {
    std::size_t left{0};
    while (left + 1 < arr.size() && arr[left] <= arr[left + 1]) ++left;
    if (left + 1 == arr.size()) return 0;

    std::size_t right{arr.size() - 1};
    while (arr[right - 1] <= arr[right]) --right;

    std::size_t removed = std::min(arr.size() - left - 1, right);

    std::size_t l{0}, r{right};
    while (l <= left && r < arr.size()) {
      if (arr[l] <= arr[r]) {
        if (r - l - 1 < removed) removed = r - l - 1;
        ++l;
      } else {
        ++r;
      }
    }

    return removed;
  }
};
