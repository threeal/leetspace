#include <string>
#include <vector>

extern "C" {
int numOfPairs(char** nums, int numsSize, char* target);
}

int solution_c(std::vector<std::string> nums, std::string target) {
  std::vector<char*> numsDatas(nums.size());
  for (std::size_t i{0}; i < nums.size(); ++i) {
    numsDatas[i] = nums[i].data();
  }

  return numOfPairs(numsDatas.data(), nums.size(), target.data());
}
