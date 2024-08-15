#include <vector>

extern "C" {
int mostProfitablePath(
    int** edges, int edgesSize, int* edgesColSize,
    int bob, int* amount, int amountSize);
}

int solution_c(
    std::vector<std::vector<int>> edges, int bob, std::vector<int> amount) {
  std::vector<int*> edgesDatas(edges.size());
  std::vector<int> edgesSizes(edges.size());
  for (int i = edges.size() - 1; i >= 0; --i) {
    edgesDatas[i] = edges[i].data();
    edgesSizes[i] = edges[i].size();
  }

  return mostProfitablePath(
      edgesDatas.data(), edgesDatas.size(), edgesSizes.data(),
      bob, amount.data(), amount.size());
}
