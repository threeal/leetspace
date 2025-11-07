#include <string>
#include <vector>

class Solution {
 public:
  int numOfPairs(std::vector<std::string>& nums, std::string target) {
    int count{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      if (nums[i].size() >= target.size()) continue;

      std::size_t ii{0};
      while (ii < nums[i].size() && nums[i][ii] == target[ii]) ++ii;

      if (ii < nums[i].size()) continue;

      for (std::size_t j{0}; j < nums.size(); ++j) {
        if (i == j || ii + nums[j].size() != target.size()) continue;

        std::size_t jj{0};
        while (jj < nums[j].size() && nums[j][jj] == target[ii + jj]) ++jj;

        if (jj == nums[j].size()) ++count;
      }
    }
    return count;
  }
};
