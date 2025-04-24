#include <limits>
#include <vector>

class Solution {
 public:
  bool increasingTriplet(std::vector<int>& nums) {
    int a{std::numeric_limits<int>::max()};
    int b{std::numeric_limits<int>::max()};
    for (const int num : nums) {
      if (num <= a) {
        a = num;
      } else if (num <= b) {
        b = num;
      } else {
        return true;
      }
    }
    return false;
  }
};
