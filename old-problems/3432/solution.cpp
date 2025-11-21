#include <vector>

class Solution {
 public:
  int countPartitions(std::vector<int>& nums) {
    int right{0};
    for (const int num : nums) right += num;

    nums.pop_back();

    int count{0}, left{0};
    for (const int num : nums) {
      left += num;
      right -= num;

      if (left % 2 == right % 2) ++count;
    }

    return count;
  }
};
