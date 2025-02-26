#include <vector>

class Solution {
 public:
  std::vector<int> circularPermutation(int n, int start) {
    std::vector<int> output(1 << n);
    for (std::size_t i{0}; i < output.size(); ++i) {
      output[i] = i ^ (i >> 1) ^ start;
    }
    return output;
  }
};
