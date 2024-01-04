#include <unordered_map>
#include <vector>

class Solution {
 public:
  int minOperations(std::vector<int>& nums) {
    std::unordered_map<int, int> counts;

    for (const auto num : nums) {
      ++counts[num];
    }

    int operations = 0;
    for (const auto [num, count] : counts) {
      if (count < 2) return -1;
      operations += count / 3;
      if (count % 3 > 0) ++operations;
    }

    return operations;
  }
};
