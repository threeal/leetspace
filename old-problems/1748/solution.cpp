#include <vector>

class Solution {
 public:
  int sumOfUnique(std::vector<int>& nums) {
    int sum{0}, freqs[101]{0};
    for (const int num : nums) {
      switch (++freqs[num]) {
        case 1:
          sum += num;
          break;

        case 2:
          sum -= num;
          break;
      }
    }
    return sum;
  }
};
