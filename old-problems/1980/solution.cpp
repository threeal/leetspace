#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  std::string findDifferentBinaryString(std::vector<std::string>& nums) {
    std::sort(nums.begin(), nums.end());
    std::string res(nums.size(), '0');
    for (const auto& num : nums) {
      if (num != res) break;
      auto c = res.rbegin();
      *c += 1;
      while (*c == '2') {
        *c = '0';
        ++c;
        *c += 1;
      }
    }
    return res;
  }
};
