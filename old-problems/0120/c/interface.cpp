#include <vector>

extern "C" {
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize);
}

int solution_c(std::vector<std::vector<int>> triangle) {
  std::vector<int*> triangleDatas(triangle.size());
  std::vector<int> triangleSizes(triangle.size());
  for (int i = triangle.size() - 1; i >= 0; --i) {
    triangleDatas[i] = triangle[i].data();
    triangleSizes[i] = triangle[i].size();
  }

  return minimumTotal(
      triangleDatas.data(), triangleDatas.size(), triangleSizes.data());
}
