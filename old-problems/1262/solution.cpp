#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxSumDivThree(std::vector<int>& nums) {
    int min1{100000}, min11{100000};
    int min2{100000}, min22{100000};

    int sum{0};
    for (const int num : nums) {
      sum += num;

      switch (num % 3) {
        case 1:
          if (num < min1) {
            min11 = min1;
            min1 = num;
          } else if (num < min11) {
            min11 = num;
          }
          break;

        case 2:
          if (num < min2) {
            min22 = min2;
            min2 = num;
          } else if (num < min22) {
            min22 = num;
          }
          break;
      }
    }

    switch (sum % 3) {
      case 1:
        return sum - std::min(min1, min2 + min22);

      case 2:
        return sum - std::min(min2, min1 + min11);
    }

    return sum;
  }
};
