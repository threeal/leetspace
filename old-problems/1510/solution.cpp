#include <vector>

class Solution {
 public:
  bool winnerSquareGame(int n) {
    std::vector<bool> wins(n + 1, false);
    for (int i{1}; i <= n; ++i) {
      for (int j{1}; j * j <= i; ++j) {
        if (!wins[i - j * j]) {
          wins[i] = true;
          break;
        }
      }
    }
    return wins[n];
  }
};
