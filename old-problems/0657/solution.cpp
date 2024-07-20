#include <string>

class Solution {
 public:
  bool judgeCircle(std::string moves) {
    int horizontal{0}, vertical{0};
    for (const auto move : moves) {
      switch (move) {
        case 'L':
          --horizontal;
          break;

        case 'R':
          ++horizontal;
          break;

        case 'U':
          --vertical;
          break;

        case 'D':
          ++vertical;
      }
    }
    return horizontal == 0 && vertical == 0;
  }
};
