#include <string>
#include <vector>

class Solution {
 public:
  int finalPositionOfSnake(int n, std::vector<std::string>& commands) {
    int position{0};
    for (const std::string& command : commands) {
      switch (command[0]) {
        case 'U':
          position -= n;
          break;

        case 'R':
          ++position;
          break;

        case 'D':
          position += n;
          break;

        case 'L':
          --position;
          break;
      }
    }
    return position;
  }
};
