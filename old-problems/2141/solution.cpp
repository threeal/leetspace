#include <algorithm>
#include <vector>

class Solution {
 public:
  long long maxRunTime(int n, std::vector<int>& batteries) {
    long long low{0}, high{0};
    for (const int battery : batteries) high += battery;

    while (low < high) {
      const long long mid{high - (high - low) / 2};
      long long extra{0};

      for (const int battery : batteries) {
        extra += std::min<long long>(battery, mid);
      }

      if (extra >= n * mid) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }

    return low;
  }
};
