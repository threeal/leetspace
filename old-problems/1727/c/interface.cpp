#include <vector>

extern "C" {
int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize);
}

int solution_c(std::vector<std::vector<int>> matrix) {
  std::vector<int*> matrixData(matrix.size());
  std::vector<int> matrixColSize(matrix.size());
  for (std::size_t i = 0; i < matrix.size(); ++i) {
    matrixData[i] = matrix[i].data();
    matrixColSize[i] = matrix[i].size();
  }

  return largestSubmatrix(matrixData.data(), matrix.size(), matrixColSize.data());
}
