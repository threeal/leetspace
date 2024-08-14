#include <vector>

extern "C" {
int maxStarSum(
    int* vals, int valsSize,
    int** edges, int edgesSize, int* edgesColSize, int k);
}

int solution_c(
    std::vector<int> vals, std::vector<std::vector<int>> edges, int k) {
  std::vector<int*> edgesDatas(edges.size());
  std::vector<int> edgesSizes(edges.size());
  for (int i = edges.size() - 1; i >= 0; --i) {
    edgesDatas[i] = edges[i].data();
    edgesSizes[i] = edges[i].size();
  }

  return maxStarSum(
      vals.data(), vals.size(),
      edgesDatas.data(), edgesDatas.size(), edgesSizes.data(), k);
}
