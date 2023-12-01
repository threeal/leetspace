#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> sortByBits(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end(), [](int a, int b) {
      int ai = __builtin_popcount(a);
      int bi = __builtin_popcount(b);
      return ai == bi ? a < b : ai < bi;
    });
    return arr;
  }
};
