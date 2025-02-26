#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> circularPermutation(int n, int start) {
    std::vector<int> output(1 << n);
    output[0] = 0;
    output[1] = 1;

    for (int i{1}; i < n; ++i) {
      for (int l{(1 << i) - 1}, r{1 << i}; l >= 0; --l, ++r) {
        output[r] = (1 << i) | output[l];
      }
    }

    const auto it = std::find(output.begin(), output.end(), start);
    std::rotate(output.begin(), it, output.end());

    return output;
  }
};
