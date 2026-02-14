#include <cstring>
#include <vector>

extern "C" {
int* sumEvenAfterQueries(
    int* nums, int numsSize,
    int** queries, int queriesSize, int* queriesColSize,
    int* returnSize);
}

std::vector<int> solution_c(
    std::vector<int> nums, std::vector<std::vector<int>> queries) {
  std::vector<int*> queriesDatas(queries.size());
  std::vector<int> queriesSizes(queries.size());
  for (std::size_t i{0}; i < queries.size(); ++i) {
    queriesDatas[i] = queries[i].data();
    queriesSizes[i] = queries[i].size();
  }

  int returnSize{};
  int* returnData{
      sumEvenAfterQueries(
          nums.data(), nums.size(),
          queriesDatas.data(), queries.size(), queriesSizes.data(),
          &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, output.size() * sizeof(int));

  return output;
}
