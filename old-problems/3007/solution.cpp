#include <algorithm>

class Solution {
 public:
  long long findMaximumNumber(long long k, int x) {
    long long low{0};
    long long high{10000000000000000};

    while (low < high) {
      long long mid = low + (high - low + 1) / 2;

      long long price{0};
      for (long long i = 1 << (x - 1); i <= mid; i <<= x) {
        price += (mid + 1) / (i + i) * i +
            std::max(0LL, (mid + 1) % (i + i) - i);
      }

      if (price <= k) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }

    return low;
  }
};
