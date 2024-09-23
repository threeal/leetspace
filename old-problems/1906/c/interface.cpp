#include <cstring>
#include <vector>

extern "C" {
int* minDifference(
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
  const int* returnData = minDifference(
      nums.data(), nums.size(),
      queriesDatas.data(), queriesDatas.size(), queriesSizes.data(),
      &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
