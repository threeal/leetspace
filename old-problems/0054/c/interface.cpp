#include <cstring>
#include <vector>

extern "C" {
int* spiralOrder(
    int** matrix, int matrixSize, int* matrixColSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<std::vector<int>> matrix) {
  std::vector<int*> matrixDatas(matrix.size());
  std::vector<int> matrixSizes(matrix.size());
  for (std::size_t i{0}; i < matrix.size(); ++i) {
    matrixDatas[i] = matrix[i].data();
    matrixSizes[i] = matrix[i].size();
  }

  int returnSize{};
  int* returnData{
      spiralOrder(
          matrixDatas.data(), matrix.size(), matrixSizes.data(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
  ;
}
