#include <cstring>
#include <vector>

extern "C" {
int* eventualSafeNodes(
    int** graph, int graphSize, int* graphColSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<std::vector<int>> graph) {
  std::vector<int*> graphDatas(graph.size());
  std::vector<int> graphSizes(graph.size());
  for (std::size_t i{0}; i < graph.size(); ++i) {
    graphDatas[i] = graph[i].data();
    graphSizes[i] = graph[i].size();
  }

  int returnSize{};
  int* returnData = eventualSafeNodes(
      graphDatas.data(), graphDatas.size(), graphSizes.data(), &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
