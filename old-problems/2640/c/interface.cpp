#include <cstring>
#include <vector>

extern "C" {
long long* findPrefixScore(int* nums, int numsSize, int* returnSize);
}

std::vector<long long> solution_c(std::vector<int> nums) {
  int returnSize{};
  long long* returnData{findPrefixScore(nums.data(), nums.size(), &returnSize)};

  std::vector<long long> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(long long));

  return output;
}
