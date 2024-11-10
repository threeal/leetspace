#include <cstring>
#include <vector>

extern "C" {
int** matrixReshape(
    int** mat, int matSize, int* matColSize, int r, int c,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<std::vector<int>> mat, int r, int c) {
  std::vector<int*> matDatas(mat.size());
  std::vector<int> matSizes(mat.size());
  for (std::size_t i{0}; i < mat.size(); ++i) {
    matDatas[i] = mat[i].data();
    matSizes[i] = mat[i].size();
  }

  int returnSize{};
  int* returnColumnSizes{};
  int** returnData = matrixReshape(
      matDatas.data(), matDatas.size(), matSizes.data(), r, c,
      &returnSize, &returnColumnSizes);

  std::vector<std::vector<int>> output(returnSize);
  for (int i{0}; i < returnSize; ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
