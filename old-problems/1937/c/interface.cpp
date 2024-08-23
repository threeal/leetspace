#include <vector>

extern "C" {
long long maxPoints(int** points, int pointsSize, int* pointsColSize);
}

long long solution_c(std::vector<std::vector<int>> points) {
  std::vector<int*> pointsDatas(points.size());
  std::vector<int> pointsSizes(points.size());
  for (int i = points.size() - 1; i >= 0; --i) {
    pointsDatas[i] = points[i].data();
    pointsSizes[i] = points[i].size();
  }

  return maxPoints(pointsDatas.data(), pointsDatas.size(), pointsSizes.data());
}
