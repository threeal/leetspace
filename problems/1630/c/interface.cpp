#include <vector>

extern "C" {
bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize);
}

std::vector<bool> solution_c(std::vector<int> nums, std::vector<int> l, std::vector<int> r) {
  int returnSize;
  const auto returnData = checkArithmeticSubarrays(nums.data(), nums.size(), l.data(), l.size(), r.data(), r.size(), &returnSize);

  std::vector<bool> res(returnSize);
  for (int i = 0; i < returnSize; ++i) {
    res[i] = returnData[i];
  }
  return res;
}
