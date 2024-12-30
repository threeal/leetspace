#include <cstring>
#include <vector>

extern "C" {
int* getFinalState(
    int* nums, int numsSize, int k, int multiplier, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums, int k, int multiplier) {
  int returnSize{};
  const auto data = getFinalState(
      nums.data(), nums.size(), k, multiplier, &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), data, returnSize * sizeof(int));

  return output;
}
