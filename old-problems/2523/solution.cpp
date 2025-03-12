#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> closestPrimes(int left, int right) {
    std::vector<bool> flags(right + 1, false);

    for (int i{2}; i < left; ++i) {
      if (!flags[i]) {
        for (int j{i + i}; j <= right; j += i) flags[j] = true;
      }
    }

    int a{-right}, b{right}, prev{-right};
    for (int i{std::max(left, 2)}; i <= right; ++i) {
      if (!flags[i]) {
        if (i - prev < b - a) a = prev, b = i;
        for (int j{i + i}; j <= right; j += i) flags[j] = true;
        prev = i;
      }
    }

    if (a < 0) return {-1, -1};
    return {a, b};
  }
};
