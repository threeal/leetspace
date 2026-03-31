#include <vector>

extern "C" {
int minFlips(int** mat, int matSize, int* matColSize);
}

int solution_c(std::vector<std::vector<int>> mat) {
  std::vector<int*> matDatas(mat.size());
  std::vector<int> matSizes(mat.size());
  for (std::size_t i{0}; i < mat.size(); ++i) {
    matDatas[i] = mat[i].data();
    matSizes[i] = mat[i].size();
  }

  return minFlips(matDatas.data(), mat.size(), matSizes.data());
}
