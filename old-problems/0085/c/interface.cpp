#include <vector>

extern "C" {
int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize);
}

int solution_c(std::vector<std::vector<char>> matrix) {
  std::vector<char*> matrixDatas(matrix.size());
  std::vector<int> matrixSizes(matrix.size());
  for (std::size_t i{0}; i < matrix.size(); ++i) {
    matrixDatas[i] = matrix[i].data();
    matrixSizes[i] = matrix[i].size();
  }

  return maximalRectangle(
      matrixDatas.data(), matrix.size(), matrixSizes.data());
}
