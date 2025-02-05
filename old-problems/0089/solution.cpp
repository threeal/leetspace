#include <vector>

class Solution {
 public:
  std::vector<int> grayCode(int n) {
    std::vector<int> output(1 << n);
    output[0] = 0;
    output[1] = 1;

    for (int i{1}; i < n; ++i) {
      for (int l{(1 << i) - 1}, r{1 << i}; l >= 0; --l, ++r) {
        output[r] = (1 << i) | output[l];
      }
    }

    return output;
  }
};
