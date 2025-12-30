#include <cstring>
#include <vector>

extern "C" {
int** rangeAddQueries(
    int n, int** queries, int queriesSize, int* queriesColSize,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    int n, std::vector<std::vector<int>> queries) {
  std::vector<int*> queriesDatas(queries.size());
  std::vector<int> queriesSizes(queries.size());
  for (std::size_t i{0}; i < queries.size(); ++i) {
    queriesDatas[i] = queries[i].data();
    queriesSizes[i] = queries[i].size();
  }

  int returnSize{};
  int* returnColumnSizes{};
  int** returnData{
      rangeAddQueries(
          n, queriesDatas.data(), queries.size(), queriesSizes.data(),
          &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
