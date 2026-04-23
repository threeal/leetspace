#include <vector>

extern "C" {
bool areSimilar(int** mat, int matSize, int* matColSize, int k);
}

bool solution_c(std::vector<std::vector<int>> mat, int k) {
  std::vector<int*> matDatas(mat.size());
  std::vector<int> matSizes(mat.size());
  for (std::size_t i{0}; i < mat.size(); ++i) {
    matDatas[i] = mat[i].data();
    matSizes[i] = mat[i].size();
  }

  return areSimilar(matDatas.data(), mat.size(), matSizes.data(), k);
}
