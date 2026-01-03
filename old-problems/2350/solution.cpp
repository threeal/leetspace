#include <vector>

class Solution {
 public:
  int shortestSequence(std::vector<int>& rolls, int k) {
    std::vector<bool> exists(k + 1, false);
    int existCount{0};

    int shortest{1};
    for (std::size_t i{0}; i < rolls.size(); ++i) {
      if (!exists[rolls[i]]) {
        if (++existCount == k) {
          ++shortest;
          exists.assign(k + 1, false);
          existCount = 0;
        } else {
          exists[rolls[i]] = true;
        }
      }
    }

    return shortest;
  }
};
