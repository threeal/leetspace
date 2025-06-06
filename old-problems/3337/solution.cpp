#include <string>
#include <vector>

class Solution {
 public:
  int lengthAfterTransformations(std::string s, int t, std::vector<int>& nums) {
    return s.size() + t + nums.size();
  }
};
