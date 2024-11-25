#include <algorithm>
#include <vector>

class Solution {
 public:
  int minimizedMaximum(int n, std::vector<int>& quantities) {
    int low{1};
    int high = *std::max_element(quantities.begin(), quantities.end());

    while (low < high) {
      const int mid = low + (high - low) / 2;

      int count{0};
      for (const auto quantity : quantities) {
        count += quantity / mid;
        if (quantity % mid != 0) ++count;
      }

      if (count <= n) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    return low;
  }
};
