#include <algorithm>
#include <functional>
#include <limits>
#include <vector>

class Solution {
 public:
  int maxDotProduct(std::vector<int>& nums1, std::vector<int>& nums2) {
    static const int min_val = std::numeric_limits<int>::min();

    const int n1 = nums1.size();
    const int n2 = nums2.size();

    auto cache = std::vector(n1, std::vector(n2, min_val));

    const std::function<int(int, int)> fn = [&](int i1, int i2) -> int {
      if (i1 >= n1 || i2 >= n2) return min_val;

      if (cache[i1][i2] > min_val) return cache[i1][i2];

      cache[i1][i2] = std::max({nums1[i1] * nums2[i2] + std::max(fn(i1 + 1, i2 + 1), 0),
                                fn(i1 + 1, i2),
                                fn(i1, i2 + 1),
                                fn(i1 + 1, i2 + 1)});

      return cache[i1][i2];
    };

    return fn(0, 0);
  }
};
