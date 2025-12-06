#include <vector>

extern "C" {
int numberOfPoints(int** nums, int numsSize, int* numsColSize);
}

int solution_c(std::vector<std::vector<int>> nums) {
  std::vector<int*> numsDatas(nums.size());
  std::vector<int> numsSizes(nums.size());
  for (std::size_t i{0}; i < nums.size(); ++i) {
    numsDatas[i] = nums[i].data();
    numsSizes[i] = nums[i].size();
  }

  return numberOfPoints(numsDatas.data(), nums.size(), numsSizes.data());
}
