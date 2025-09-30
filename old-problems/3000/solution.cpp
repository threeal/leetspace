#include <vector>

class Solution {
 public:
  int areaOfMaxDiagonal(std::vector<std::vector<int>>& dimensions) {
    int maxDiagonal{0}, maxArea{0};
    for (const auto& dim : dimensions) {
      const int diagonal{dim[0] * dim[0] + dim[1] * dim[1]};
      if (diagonal >= maxDiagonal) {
        const int area{dim[0] * dim[1]};
        if (diagonal > maxDiagonal) {
          maxDiagonal = diagonal;
          maxArea = area;
        } else if (area > maxArea) {
          maxArea = area;
        }
      }
    }
    return maxArea;
  }
};
