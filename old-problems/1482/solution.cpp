#include <algorithm>
#include <vector>

class Solution {
 public:
  int minDays(std::vector<int>& bloomDay, int m, int k) {
    const std::size_t expectedSize =
        static_cast<std::size_t>(m) * static_cast<std::size_t>(k);
    if (bloomDay.size() < expectedSize) return -1;

    int high{*std::max_element(bloomDay.begin(), bloomDay.end())};
    if (bloomDay.size() == expectedSize) return high;

    int low{*std::min_element(bloomDay.begin(), bloomDay.end())};
    while (low < high) {
      const int mid{(low + high) / 2};

      int bouquets{0};
      for (int i = bloomDay.size() - 1; i >= 0; --i) {
        if (bloomDay[i] > mid) continue;
        if (i < k - 1) break;

        int j{k};
        while (--j > 0) {
          if (bloomDay[--i] > mid) break;
        }

        if (j <= 0) ++bouquets;
      }

      if (bouquets < m) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }

    return low;
  }
};
