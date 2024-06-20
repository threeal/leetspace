#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxDistance(std::vector<int>& position, int m) {
    std::sort(position.begin(), position.end());

    int low{1};
    int high{(position.back() - position.front()) / (m - 1)};
    while (low < high) {
      const int mid{(low + high + 1) / 2};

      int balls{1};
      auto it = position.begin();
      while (balls <= m) {
        it = std::lower_bound(it, position.end(), *it + mid);
        if (it == position.end()) break;
        ++balls;
      }

      if (balls < m) {
        high = mid - 1;
      } else {
        low = mid;
      }
    }

    return high;
  }
};
