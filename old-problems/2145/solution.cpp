#include <vector>

class Solution {
 public:
  int numberOfArrays(std::vector<int>& differences, int lower, int upper) {
    return differences.size() + upper - lower;
  }
};
