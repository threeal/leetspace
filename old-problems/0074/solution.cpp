#include <vector>

class Solution {
 public:
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    std::size_t vLow{0}, vHigh{matrix.size() - 1};
    while (vLow < vHigh) {
      std::size_t mid{vLow + (vHigh - vLow) / 2};
      if (matrix[mid].back() < target) {
        vLow = mid + 1;
      } else {
        vHigh = mid;
      }
    }

    if (matrix[vLow].back() < target) return false;

    std::size_t hLow{0}, hHigh{matrix[vLow].size() - 1};
    while (hLow < hHigh) {
      std::size_t mid{hLow + (hHigh - hLow) / 2};
      if (matrix[vLow][mid] < target) {
        hLow = mid + 1;
      } else {
        hHigh = mid;
      }
    }

    return matrix[vLow][hLow] == target;
  }
};
