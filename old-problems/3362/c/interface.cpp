#include <vector>

extern "C" {
int maxRemoval(
    int* nums, int numsSize,
    int** queries, int queriesSize, int* queriesColSize);
}

int solution_c(std::vector<int> nums, std::vector<std::vector<int>> queries) {
  std::vector<int*> queriesDatas(queries.size());
  std::vector<int> queriesSizes(queries.size());
  for (std::size_t i{0}; i < queries.size(); ++i) {
    queriesDatas[i] = queries[i].data();
    queriesSizes[i] = queries[i].size();
  }

  return maxRemoval(
      nums.data(), nums.size(),
      queriesDatas.data(), queriesDatas.size(), queriesSizes.data());
}
