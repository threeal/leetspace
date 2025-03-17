#include <vector>

class Solution {
 public:
  bool divideArray(std::vector<int>& nums) {
    int freqs[501]{0};

    int odds{0};
    for (const auto num : nums) {
      if (++freqs[num] % 2 == 0) {
        --odds;
      } else {
        ++odds;
      }
    }

    return odds == 0;
  }
};
