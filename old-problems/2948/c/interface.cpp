#include <cstring>
#include <vector>

extern "C" {
int* lexicographicallySmallestArray(
    int* nums, int numsSize, int limit, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums, int limit) {
  int returnSize{};
  int* returnData = lexicographicallySmallestArray(
      nums.data(), nums.size(), limit, &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
