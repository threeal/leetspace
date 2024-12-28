#include <cstring>
#include <vector>

extern "C" {
int* finalPrices(int* prices, int pricesSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums) {
  int returnSize;
  const auto returnData = finalPrices(nums.data(), nums.size(), &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
