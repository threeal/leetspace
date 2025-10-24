#include <cstring>
#include <vector>

extern "C" {
int** matrixBlockSum(
    int** mat, int matSize, int* matColSize, int k,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<std::vector<int>> mat, int k) {
  std::vector<int*> matDatas(mat.size());
  std::vector<int> matSizes(mat.size());
  for (std::size_t i{0}; i < mat.size(); ++i) {
    matDatas[i] = mat[i].data();
    matSizes[i] = mat[i].size();
  }

  int returnSize{};
  int* returnColumnSizes{};
  int** returnData{
      matrixBlockSum(
          matDatas.data(), mat.size(), matSizes.data(), k,
          &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
