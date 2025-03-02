#include <vector>

extern "C" {
bool* areConnected(
    int n, int threshold, int** queries, int queriesSize, int* queriesColSize,
    int* returnSize);
}

std::vector<bool> solution_c(
    int n, int threshold, std::vector<std::vector<int>> queries) {
  std::vector<int*> queriesDatas(queries.size());
  std::vector<int> queriesSizes(queries.size());
  for (std::size_t i{0}; i < queries.size(); ++i) {
    queriesDatas[i] = queries[i].data();
    queriesSizes[i] = queries[i].size();
  }

  int returnSize{};
  bool* returnData = areConnected(
      n, threshold, queriesDatas.data(), queriesDatas.size(),
      queriesSizes.data(), &returnSize);

  std::vector<bool> output(returnSize);
  for (int i{0}; i < returnSize; ++i) {
    output[i] = returnData[i];
  }

  return output;
}
