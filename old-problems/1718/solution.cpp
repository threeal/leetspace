#include <vector>

class Solution {
 public:
  std::vector<int> constructDistancedSequence(int n) {
    return std::vector(n * 2 - 1, 0);
  }
};
