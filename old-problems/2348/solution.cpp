#include <vector>

class Solution {
 public:
  long long zeroFilledSubarray(std::vector<int>& nums) {
    long long count{0}, zeros{0};
    for (const auto num : nums) {
      if (num == 0) {
        ++zeros;
      } else {
        count += ((zeros + 1) * zeros) / 2;
        zeros = 0;
      }
    }
    return count + ((zeros + 1) * zeros) / 2;
  }
};
