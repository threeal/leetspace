#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> targetIndices(std::vector<int>& nums, int target) {
    int less{0}, equal{0};
    for (const int num : nums) {
      if (num < target) {
        ++less;
      } else if (num == target) {
        ++equal;
      }
    }

    std::vector<int> output(equal);
    std::iota(output.begin(), output.end(), less);

    return output;
  }
};
