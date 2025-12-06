#include <cstring>
#include <vector>

extern "C" {
int* occurrencesOfElement(
    int* nums, int numsSize, int* queries, int queriesSize, int x,
    int* returnSize);
}

std::vector<int> solution_c(
    std::vector<int> nums, std::vector<int> queries, int x) {
  int returnSize{};
  int* returnData{
      occurrencesOfElement(
          nums.data(), nums.size(), queries.data(), queries.size(), x,
          &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
