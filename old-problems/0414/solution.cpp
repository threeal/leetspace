#include <utility>
#include <vector>

class Solution {
 public:
  int thirdMax(std::vector<int>& nums) {
    int a{nums[0]};

    std::size_t i{1};
    while (i < nums.size() && nums[i] == a) ++i;
    if (i == nums.size()) return a;
    int b{nums[i]};
    if (b > a) std::swap(a, b);

    ++i;
    while (i < nums.size() && (nums[i] == a || nums[i] == b)) ++i;
    if (i == nums.size()) return a;
    int c{nums[i]};
    if (c > b) std::swap(c, b);
    if (b > a) std::swap(b, a);

    ++i;
    while (i < nums.size()) {
      if (nums[i] >= a) {
        if (nums[i] > a) {
          c = b;
          b = a;
          a = nums[i];
        }
      } else if (nums[i] >= b) {
        if (nums[i] > b) {
          c = b;
          b = nums[i];
        }
      } else if (nums[i] > c) {
        c = nums[i];
      }
      ++i;
    }

    return c;
  }
};
