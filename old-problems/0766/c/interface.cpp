#include <vector>

extern "C" {
bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize);
}

bool solution_c(std::vector<std::vector<int>> matrix) {
  std::vector<int*> matrixDatas(matrix.size());
  std::vector<int> matrixSizes(matrix.size());
  for (std::size_t i{0}; i < matrix.size(); ++i) {
    matrixDatas[i] = matrix[i].data();
    matrixSizes[i] = matrix[i].size();
  }

  return isToeplitzMatrix(
      matrixDatas.data(), matrix.size(), matrixSizes.data());
}
