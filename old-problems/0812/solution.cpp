#include <vector>

class Solution {
 public:
  double largestTriangleArea(std::vector<std::vector<int>>& points) {
    int largestArea{0};
    for (int i = points.size() - 1; i >= 2; --i) {
      for (int j = i - 1; j >= 1; --j) {
        for (int k = j - 1; k >= 0; --k) {
          int area{
              points[i][0] * (points[j][1] - points[k][1]) +
              points[j][0] * (points[k][1] - points[i][1]) +
              points[k][0] * (points[i][1] - points[j][1])};
          if (area < 0) area = -area;
          if (area > largestArea) largestArea = area;
        }
      }
    }
    return largestArea * 0.5;
  }
};
