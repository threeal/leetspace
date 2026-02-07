#include <cstring>
#include <vector>

extern "C" {
int** modifiedMatrix(
    int** matrix, int matrixSize, int* matrixColSize,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(std::vector<std::vector<int>> matrix) {
  std::vector<int*> matrixDatas(matrix.size());
  std::vector<int> matrixSizes(matrix.size());
  for (std::size_t i{0}; i < matrix.size(); ++i) {
    matrixDatas[i] = matrix[i].data();
    matrixSizes[i] = matrix[i].size();
  }

  int returnSize{};
  int* returnColumnSizes{};
  int** returnData{
      modifiedMatrix(
          matrixDatas.data(), matrix.size(), matrixSizes.data(),
          &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], output[i].size() * sizeof(int));
  }

  return output;
}
