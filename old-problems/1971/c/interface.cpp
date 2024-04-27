#include <vector>

extern "C" {
bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination);
}

int solution_c(int n, std::vector<std::vector<int>> edges, int source, int destination) {
  std::vector<int*> edgesDatas(edges.size());
  std::vector<int> edgesSizes(edges.size());
  for (std::size_t i{0}; i < edges.size(); ++i) {
    edgesDatas[i] = edges[i].data();
    edgesSizes[i] = edges[i].size();
  }

  return validPath(n, edgesDatas.data(), edgesDatas.size(), edgesSizes.data(), source, destination);
}
