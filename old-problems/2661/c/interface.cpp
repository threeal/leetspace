#include <cstring>
#include <vector>

extern "C" {
int firstCompleteIndex(
    int* arr, int arrSize, int** mat, int matSize, int* matColSize);
}

int solution_c(std::vector<int> arr, std::vector<std::vector<int>> mat) {
  std::vector<int*> matDatas(mat.size());
  std::vector<int> matSizes(mat.size());
  for (std::size_t i{0}; i < mat.size(); ++i) {
    matDatas[i] = mat[i].data();
    matSizes[i] = mat[i].size();
  }

  return firstCompleteIndex(
      arr.data(), arr.size(),
      matDatas.data(), matDatas.size(), matSizes.data());
}
