#include <string>

class Solution {
 public:
  int countCollisions(std::string directions) {
    char* direction = directions.data();
    while (*direction == 'L') ++direction;

    int collisions{0};
    int rights{0};
    while (*direction != 0) {
      switch (*direction) {
        case 'L':
          collisions += rights + 1;
          rights = 0;
          break;

        case 'R':
          ++rights;
          break;

        case 'S':
          collisions += rights;
          rights = 0;
      }
      ++direction;
    }

    return collisions;
  }
};
