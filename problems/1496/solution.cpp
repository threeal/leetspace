#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
 public:
  bool isPathCrossing(std::string path) {
    std::unordered_map<int, std::unordered_set<int>> visited;
    visited[0].insert(0);

    int x = 0;
    int y = 0;

    for (const auto dir : path) {
      switch (dir) {
        case 'N':
          --y;
          break;

        case 'S':
          ++y;
          break;

        case 'E':
          ++x;
          break;

        case 'W':
          --x;
          break;
      }

      if (visited[x].contains(y)) return true;
      visited[x].insert(y);
    }

    return false;
  }
};
