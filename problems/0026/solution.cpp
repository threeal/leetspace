#include <unordered_set>
#include <vector>

class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    std::unordered_set<int> s;
    int k = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (s.contains(nums[i])) continue;
      s.insert(nums[i]);
      nums[k] = nums[i];
      ++k;
    }
    return k;
  }
};
