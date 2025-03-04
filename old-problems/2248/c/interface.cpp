#include <cstring>
#include <vector>

extern "C" {
int* intersection(int** nums, int numsSize, int* numsColSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<std::vector<int>> nums) {
  std::vector<int*> numsDatas(nums.size());
  std::vector<int> numsSizes(nums.size());
  for (std::size_t i{0}; i < nums.size(); ++i) {
    numsDatas[i] = nums[i].data();
    numsSizes[i] = nums[i].size();
  }

  int returnSize{};
  int* returnData = intersection(
      numsDatas.data(), numsDatas.size(), numsSizes.data(), &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
