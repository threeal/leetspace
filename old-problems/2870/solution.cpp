#include <algorithm>
#include <vector>

class Solution {
 public:
  int minOperations(std::vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int operations = 0;
    int num = nums[0];
    int count = 1;
    for (std::size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] == num) {
        ++count;
        continue;
      }

      if (count < 2) return -1;
      operations += count / 3;
      if (count % 3 > 0) ++operations;

      num = nums[i];
      count = 1;
    }

    if (count < 2) return -1;
    operations += count / 3;
    if (count % 3 > 0) ++operations;

    return operations;
  }
};
