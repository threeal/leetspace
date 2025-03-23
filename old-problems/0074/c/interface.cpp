#include <vector>

extern "C" {
bool searchMatrix(
    int** matrix, int matrixSize, int* matrixColSize, int target);
}

bool solution_c(std::vector<std::vector<int>> matrix, int target) {
  std::vector<int*> matrixDatas(matrix.size());
  std::vector<int> matrixSizes(matrix.size());
  for (std::size_t i{0}; i < matrix.size(); ++i) {
    matrixDatas[i] = matrix[i].data();
    matrixSizes[i] = matrix[i].size();
  }

  return searchMatrix(
      matrixDatas.data(), matrixDatas.size(), matrixSizes.data(), target);
}
