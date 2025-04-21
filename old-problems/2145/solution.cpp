#include <vector>

class Solution {
 public:
  int numberOfArrays(std::vector<int>& differences, int lower, int upper) {
    long long val{0}, min{0}, max{0};
    for (const int diff : differences) {
      val += diff;
      if (val > max) max = val;
      if (val < min) min = val;
    }
    return upper - lower >= max - min ? 1 + (upper - lower) - (max - min) : 0;
  }
};
