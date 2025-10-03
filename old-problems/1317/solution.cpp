#include <vector>

class Solution {
 public:
  std::vector<int> getNoZeroIntegers(int n) {
    for (int i{1}; i < n; ++i) {
      int j{i};
      while (j > 0 && j % 10 != 0) j /= 10;
      if (j > 0) continue;

      j = n - i;
      while (j > 0 && j % 10 != 0) j /= 10;
      if (j > 0) continue;

      return {i, n - i};
    }
    return {0, n};
  }
};
