#include <cstring>
#include <vector>

extern "C" {
int* findSmallestSetOfVertices(
    int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize);
}

std::vector<int> solution_c(int n, std::vector<std::vector<int>> edges) {
  std::vector<int*> edgesDatas(edges.size());
  std::vector<int> edgesSizes(edges.size());
  for (std::size_t i{0}; i < edges.size(); ++i) {
    edgesDatas[i] = edges[i].data();
    edgesSizes[i] = edges[i].size();
  }

  int returnSize{};
  int* returnData{
      findSmallestSetOfVertices(
          n, edgesDatas.data(), edges.size(), edgesSizes.data(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
