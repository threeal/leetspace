#include <cstring>
#include <vector>

extern "C" {
int* minimumCost(
    int n, int** edges, int edgesSize, int* edgesColSize,
    int** query, int querySize, int* queryColSize, int* returnSize);
}

std::vector<int> solution_c(
    int n, std::vector<std::vector<int>> edges,
    std::vector<std::vector<int>> query) {
  std::vector<int*> edgesDatas(edges.size());
  std::vector<int> edgesSizes(edges.size());
  for (std::size_t i{0}; i < edges.size(); ++i) {
    edgesDatas[i] = edges[i].data();
    edgesSizes[i] = edges[i].size();
  }

  std::vector<int*> queryDatas(query.size());
  std::vector<int> querySizes(query.size());
  for (std::size_t i{0}; i < query.size(); ++i) {
    queryDatas[i] = query[i].data();
    querySizes[i] = query[i].size();
  }

  int returnSize{};
  int* returnData = minimumCost(
      n, edgesDatas.data(), edges.size(), edgesSizes.data(),
      queryDatas.data(), query.size(), querySizes.data(), &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
