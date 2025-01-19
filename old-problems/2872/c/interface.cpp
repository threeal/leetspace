#include <cstring>
#include <vector>

extern "C" {
int maxKDivisibleComponents(
    int n, int** edges, int edgesSize, int* edgesColSize,
    int* values, int valuesSize, int k);
}

int solution_c(
    int n, std::vector<std::vector<int>> edges,
    std::vector<int> values, int k) {
  std::vector<int*> edgesDatas(edges.size());
  std::vector<int> edgesSizes(edges.size());
  for (std::size_t i{0}; i < edges.size(); ++i) {
    edgesDatas[i] = edges[i].data();
    edgesSizes[i] = edges[i].size();
  }

  return maxKDivisibleComponents(
      n, edgesDatas.data(), edgesDatas.size(), edgesSizes.data(),
      values.data(), values.size(), k);
}
