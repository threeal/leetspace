#include <vector>

extern "C" {
int findMinArrowShots(int** points, int pointsSize, int* pointsColSize);
}

int solution_c(std::vector<std::vector<int>> points) {
  std::vector<int*> pointsDatas(points.size());
  std::vector<int> pointsSizes(points.size());
  for (std::size_t i = 0; i < pointsDatas.size(); ++i) {
    pointsDatas[i] = points[i].data();
    pointsSizes[i] = points[i].size();
  }

  return findMinArrowShots(pointsDatas.data(), pointsDatas.size(), pointsSizes.data());
}
