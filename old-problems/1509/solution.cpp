#include <algorithm>
#include <limits>
#include <vector>

class Solution {
 public:
  int minDifference(std::vector<int>& nums) {
    if (nums.size() <= 4) return 0;

    int maxA{std::numeric_limits<int>::min()};
    int maxB{std::numeric_limits<int>::min()};
    int maxC{std::numeric_limits<int>::min()};
    int maxD{std::numeric_limits<int>::min()};

    int minA{std::numeric_limits<int>::max()};
    int minB{std::numeric_limits<int>::max()};
    int minC{std::numeric_limits<int>::max()};
    int minD{std::numeric_limits<int>::max()};

    for (const auto num : nums) {
      if (num > maxA) {
        maxD = maxC;
        maxC = maxB;
        maxB = maxA;
        maxA = num;
      } else if (num > maxB) {
        maxD = maxC;
        maxC = maxB;
        maxB = num;
      } else if (num > maxC) {
        maxD = maxC;
        maxC = num;
      } else if (num > maxD) {
        maxD = num;
      }

      if (num < minA) {
        minD = minC;
        minC = minB;
        minB = minA;
        minA = num;
      } else if (num < minB) {
        minD = minC;
        minC = minB;
        minB = num;
      } else if (num < minC) {
        minD = minC;
        minC = num;
      } else if (num < minD) {
        minD = num;
      }
    }

    return std::min({maxA - minD, maxB - minC, maxC - minB, maxD - minA});
  }
};
