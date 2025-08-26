#include <cstring>
#include <vector>

extern "C" {
int* findKDistantIndices(
    int* nums, int numsSize, int key, int k, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums, int key, int k) {
  int returnSize;
  int* returnData{
      findKDistantIndices(nums.data(), nums.size(), key, k, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
