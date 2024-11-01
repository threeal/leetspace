#include <algorithm>
#include <vector>

class Solution {
 public:
  int longestSquareStreak(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end(), std::greater<int>());

    char maxSquare{1};
    std::vector<char> squares(100001, 0);
    for (const auto num : nums) {
      if (num <= 316) {
        squares[num] = 1 + squares[num * num];
        if (squares[num] > maxSquare) maxSquare = squares[num];
      } else {
        squares[num] = 1;
      }
    }

    return maxSquare > 1 ? maxSquare : -1;
  }
};
