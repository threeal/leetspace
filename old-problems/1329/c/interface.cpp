#include <cstring>
#include <vector>

extern "C" {
int** diagonalSort(
    int** mat, int matSize, int* matColSize,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(std::vector<std::vector<int>> mat) {
  std::vector<int*> matDatas(mat.size());
  std::vector<int> matSizes(mat.size());
  for (int i = mat.size() - 1; i >= 0; --i) {
    matDatas[i] = mat[i].data();
    matSizes[i] = mat[i].size();
  }

  int returnSize;
  int* returnColumnSizes;
  const auto returnData = diagonalSort(
      matDatas.data(), matDatas.size(), matSizes.data(),
      &returnSize, &returnColumnSizes);

  mat.resize(returnSize);
  for (int i = returnSize - 1; i >= 0; --i) {
    mat[i].resize(returnColumnSizes[i]);
    std::memcpy(
        mat[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return mat;
}
