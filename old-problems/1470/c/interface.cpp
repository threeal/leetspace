#include <cstring>
#include <vector>

extern "C" {
int* shuffle(int* nums, int numsSize, int n, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums, int n) {
  int returnSize{};
  int* returnData{shuffle(nums.data(), nums.size(), n, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
