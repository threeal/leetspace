#include <string>
#include <vector>

extern "C" {
char* findDifferentBinaryString(char** nums, int numsSize);
}

std::string solution_c(std::vector<std::string> nums) {
  std::vector<char*> numsDatas(nums.size());
  for (std::size_t i{0}; i < nums.size(); ++i) {
    numsDatas[i] = nums[i].data();
  }
  return findDifferentBinaryString(numsDatas.data(), numsDatas.size());
}
