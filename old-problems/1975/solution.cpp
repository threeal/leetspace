#include <vector>

class Solution {
 public:
  long long maxMatrixSum(std::vector<std::vector<int>>& matrix) {
    long long sum{0};
    int negCount{0}, minVal{100000};
    bool hasZero{false};
    for (const auto& row : matrix) {
      for (const auto val : row) {
        if (val == 0) {
          hasZero = true;
        } else if (val < 0) {
          ++negCount;
          sum += -val;
          if (-val < minVal) minVal = -val;
        } else {
          sum += val;
          if (val < minVal) minVal = val;
        }
      }
    }
    if (!hasZero && negCount % 2 == 1) sum -= 2 * minVal;
    return sum;
  }
};
