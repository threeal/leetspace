#include <vector>

class Solution {
 public:
  std::vector<int> grayCode(int n) {
    return std::vector<int>(1 << n);
  }
};
