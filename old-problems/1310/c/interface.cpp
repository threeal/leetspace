#include <cstring>
#include <vector>

extern "C" {
int* xorQueries(
    int* arr, int arrSize,
    int** queries, int queriesSize, int* queriesColSize, int* returnSize);
}

std::vector<int> solution_c(
    std::vector<int> arr, std::vector<std::vector<int>> queries) {
  std::vector<int*> queriesDatas(queries.size());
  std::vector<int> queriesSizes(queries.size());
  for (std::size_t i{0}; i < queries.size(); ++i) {
    queriesDatas[i] = queries[i].data();
    queriesSizes[i] = queries[i].size();
  }

  int returnSize{};
  int* returnData{
      xorQueries(
          arr.data(), arr.size(),
          queriesDatas.data(), queries.size(), queriesSizes.data(),
          &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
