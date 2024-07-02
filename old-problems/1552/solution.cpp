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
      for (int i = position.size() - 2, prev = position.back(); i >= 0; --i) {
        if (prev - position[i] >= mid) {
          prev = position[i];
          ++balls;
        }
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
