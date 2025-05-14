#include <cstring>
#include <vector>

extern "C" {
int* createTargetArray(
    int* nums, int numsSize, int* index, int indexSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums, std::vector<int> index) {
  int returnSize{};
  int* returnData{createTargetArray(
      nums.data(), nums.size(), index.data(), index.size(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
