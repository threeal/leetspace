#include <vector>

class Solution {
 public:
  long long putMarbles(std::vector<int>& weights, int k) {
    return weights.front() + k;
  }
};
