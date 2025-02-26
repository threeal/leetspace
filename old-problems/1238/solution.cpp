#include <vector>

class Solution {
 public:
  std::vector<int> circularPermutation(int n, int start) {
    return std::vector<int>(1 << n, start);
  }
};
