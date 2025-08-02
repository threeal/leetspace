#include <cstring>
#include <vector>

extern "C" {
int oddCells(
    int m, int n, int** indices, int indicesSize, int* indicesColSize);
}

int solution_c(int m, int n, std::vector<std::vector<int>> indices) {
  std::vector<int*> indicesDatas(indices.size());
  std::vector<int> indicesSizes(indices.size());
  for (std::size_t i{0}; i < indices.size(); ++i) {
    indicesDatas[i] = indices[i].data();
    indicesSizes[i] = indices[i].size();
  }

  return oddCells(
      m, n, indicesDatas.data(), indices.size(), indicesSizes.data());
}
