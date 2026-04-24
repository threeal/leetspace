#include <string>

class Solution {
 public:
  int furthestDistanceFromOrigin(std::string moves) {
    int l{0}, r{0}, _{0};
    for (const char move : moves) {
      switch (move) {
        case 'L':
          ++l;
          break;
        case 'R':
          ++r;
          break;
        case '_':
          ++_;
          break;
      }
    }
    return l > r ? l + _ - r : r + _ - l;
  }
};
