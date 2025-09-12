#include <unordered_set>
#include <vector>

class Solution {
 public:
  int repeatedNTimes(std::vector<int>& nums) {
    std::unordered_set<int> exists{};
    for (const int num : nums) {
      if (exists.contains(num)) {
        return num;
      } else {
        exists.insert(num);
      }
    }
    return 0;
  }
};
