#include <cstring>
#include <vector>

extern "C" {
int** allPathsSourceTarget(
    int** graph, int graphSize, int* graphColSize,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(std::vector<std::vector<int>> graph) {
  std::vector<int*> graphDatas(graph.size());
  std::vector<int> graphSizes(graph.size());
  for (std::size_t i{0}; i < graph.size(); ++i) {
    graphDatas[i] = graph[i].data();
    graphSizes[i] = graph[i].size();
  }

  int returnSize{};
  int* returnColumnSizes{};
  int** returnData{
      allPathsSourceTarget(
          graphDatas.data(), graph.size(), graphSizes.data(),
          &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], output[i].size() * sizeof(int));
  }

  return output;
}
