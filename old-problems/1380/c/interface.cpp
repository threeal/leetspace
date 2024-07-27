#include <cstring>
#include <vector>

extern "C" {
int* luckyNumbers(
    int** matrix, int matrixSize, int* matrixColSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<std::vector<int>> matrix) {
  std::vector<int*> matrixDatas(matrix.size());
  std::vector<int> matrixSizes(matrix.size());
  for (int i = matrix.size() - 1; i >= 0; --i) {
    matrixDatas[i] = matrix[i].data();
    matrixSizes[i] = matrix[i].size();
  }

  int returnSize;
  const auto returnData = luckyNumbers(
      matrixDatas.data(), matrixDatas.size(), matrixSizes.data(), &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
