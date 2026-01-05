#include <vector>

extern "C" {
long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize);
}

long long solution_c(std::vector<std::vector<int>> matrix) {
  std::vector<int*> matrixDatas(matrix.size());
  std::vector<int> matrixSizes(matrix.size());
  for (std::size_t i{0}; i < matrix.size(); ++i) {
    matrixDatas[i] = matrix[i].data();
    matrixSizes[i] = matrix[i].size();
  }

  return maxMatrixSum(
      matrixDatas.data(), matrixDatas.size(), matrixSizes.data());
}
