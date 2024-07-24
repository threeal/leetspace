#include <vector>

extern "C" {
int findCenter(int** edges, int edgesSize, int* edgesColSize);
}

int solution_c(std::vector<std::vector<int>> edges) {
  std::vector<int*> edgesDatas(edges.size());
  std::vector<int> edgesSizes(edges.size());
  for (int i = edges.size() - 1; i >= 0; --i) {
    edgesDatas[i] = edges[i].data();
    edgesSizes[i] = edges[i].size();
  }

  return findCenter(
      edgesDatas.data(), edgesDatas.size(), edgesSizes.data());
}
