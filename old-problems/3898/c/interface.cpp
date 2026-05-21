#include <cstring>
#include <vector>

extern "C" {
int* findDegrees(
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
      findDegrees(matrixDatas.data(), matrix.size(), matrixSizes.data(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, output.size() * sizeof(int));

  return output;
}
