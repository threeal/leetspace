#include <cstring>
#include <vector>

extern "C" {
int* answerQueries(
    int* nums, int numsSize, int* queries, int queriesSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums, std::vector<int> queries) {
  int returnSize{};
  int* returnData{
      answerQueries(
          nums.data(), nums.size(), queries.data(), queries.size(),
          &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
