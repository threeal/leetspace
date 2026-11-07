#include <vector>

extern "C" {
int maxSideLength(int** mat, int matSize, int* matColSize, int threshold);
}

int solution_c(std::vector<std::vector<int>> mat, int threshold) {
  std::vector<int*> matDatas(mat.size());
  std::vector<int> matSizes(mat.size());
  for (std::size_t i{0}; i < mat.size(); ++i) {
    matDatas[i] = mat[i].data();
    matSizes[i] = mat[i].size();
  }

  return maxSideLength(
      matDatas.data(), matDatas.size(), matSizes.data(), threshold);
}
