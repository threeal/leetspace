#include <string>
#include <vector>

class Solution {
 public:
  int numOfPairs(std::vector<std::string>& nums, std::string target) {
    return nums.size() + target.size();
  }
};
