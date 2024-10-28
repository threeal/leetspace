#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int longestSquareStreak(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end(), std::greater<int>());

    int maxSquare{-1};
    std::unordered_map<int, int> squares{};
    for (const auto num : nums) {
      if (num <= 316) {
        const auto it = squares.find(num * num);
        if (it != squares.end()) {
          squares.emplace(num, 1 + it->second);
          if (1 + it->second > maxSquare) maxSquare = 1 + it->second;
          continue;
        }
      }

      squares.emplace(num, 1);
    }

    return maxSquare;
  }
};
