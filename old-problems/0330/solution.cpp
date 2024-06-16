#include <vector>

class Solution {
 public:
  int minPatches(std::vector<int>& nums, int n) {
    unsigned int unavailable{1};
    int patches{0};

    auto it = nums.begin();
    while (unavailable <= static_cast<unsigned int>(n)) {
      if (it != nums.end() && static_cast<unsigned int>(*it) <= unavailable) {
        unavailable += *it;
        ++it;
      } else {
        unavailable += unavailable;
        ++patches;
      }
    }

    return patches;
  }
};
