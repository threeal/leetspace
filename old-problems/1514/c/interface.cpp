#include <cstring>
#include <vector>

extern "C" {
double maxProbability(
    int n, int** edges, int edgesSize, int* edgesColSize,
    double* succProb, int succProbSize, int start_node, int end_node);
}

double solution_c(
    int n, std::vector<std::vector<int>> edges,
    std::vector<double> succProb, int start_node, int end_node) {
  std::vector<int*> edgesDatas(edges.size());
  std::vector<int> edgesSizes(edges.size());
  for (int i = edges.size() - 1; i >= 0; --i) {
    edgesDatas[i] = edges[i].data();
    edgesSizes[i] = edges[i].size();
  }

  return maxProbability(
      n, edgesDatas.data(), edgesDatas.size(), edgesSizes.data(),
      succProb.data(), succProb.size(), start_node, end_node);
}
