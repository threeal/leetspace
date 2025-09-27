#include <cstring>
#include <vector>

extern "C" {
int* findDiagonalOrder(
    int** mat, int matSize, int* matColSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<std::vector<int>> mat) {
  std::vector<int*> matDatas(mat.size());
  std::vector<int> matSizes(mat.size());
  for (std::size_t i{0}; i < mat.size(); ++i) {
    matDatas[i] = mat[i].data();
    matSizes[i] = mat[i].size();
  }

  int returnSize{};
  int* returnData{
      findDiagonalOrder(
          matDatas.data(), mat.size(), matSizes.data(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
