#include <vector>

extern "C" {
int numSubmatrixSumTarget(
    int** matrix, int matrixSize, int* matrixColSize, int target);
}

int solution_c(std::vector<std::vector<int>> matrix, int target) {
  std::vector<int*> matrixDatas(matrix.size());
  std::vector<int> matrixSizes(matrix.size());
  for (std::size_t i{0}; i < matrix.size(); ++i) {
    matrixDatas[i] = matrix[i].data();
    matrixSizes[i] = matrix[i].size();
  }

  return numSubmatrixSumTarget(
      matrixDatas.data(), matrixDatas.size(), matrixSizes.data(), target);
}
