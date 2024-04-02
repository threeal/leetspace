#include <cstdlib>
#include <cstring>
#include <vector>

extern "C" {
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(std::vector<std::vector<int>> matrix) {
  std::vector<int*> matrixDatas(matrix.size());
  std::vector<int> matrixSizes(matrix.size());
  for (std::size_t i = 0; i < matrix.size(); ++i) {
    matrixDatas[i] = matrix[i].data();
    matrixSizes[i] = matrix[i].size();
  }

  int returnSize;
  int* returnColumnSizes;
  const auto returnData = transpose(matrixDatas.data(), matrixDatas.size(), matrixSizes.data(), &returnSize, &returnColumnSizes);

  matrix.resize(returnSize);
  for (std::size_t i = 0; i < matrix.size(); ++i) {
    matrix[i].resize(returnColumnSizes[i]);
    memcpy(matrix[i].data(), returnData[i], sizeof(int) * matrix[i].size());
    free(returnData[i]);
  }
  free(returnColumnSizes);
  free(returnData);

  return matrix;
}
