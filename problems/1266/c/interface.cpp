#include <vector>

extern "C" {
int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize);
}

int solution_c(std::vector<std::vector<int>> points) {
  std::vector<int*> pointsData(points.size());
  std::vector<int> pointsColSize(points.size());
  for (std::size_t i = 0; i < points.size(); ++i) {
    pointsData[i] = points[i].data();
    pointsColSize[i] = points[i].size();
  }

  return minTimeToVisitAllPoints(pointsData.data(), points.size(), pointsColSize.data());
}
