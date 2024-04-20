#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> findFarmland(std::vector<std::vector<int>>& land) {
    std::vector<std::vector<int>> coordinates{};
    for (int y1{0}; y1 < static_cast<int>(land.size()); ++y1) {
      for (int x1{0}; x1 < static_cast<int>(land[y1].size()); ++x1) {
        if (land[y1][x1] != 1) continue;

        // Search for the bottom limit.
        int y2{y1 + 1};
        while (y2 < static_cast<int>(land.size())) {
          if (land[y2][x1] != 1) break;
          ++y2;
        }

        // Search for the right limit.
        int x2{x1 + 1};
        while (x2 < static_cast<int>(land[y1].size())) {
          if (land[y1][x2] != 1) break;
          ++x2;
        }

        coordinates.push_back({y1, x1, y2 - 1, x2 - 1});

        // Clear the farmland, preventing it from being counted twice.
        for (int y{y1}; y < y2; ++y) {
          for (int x{x1}; x < x2; ++x) {
            land[y][x] = 0;
          }
        }
      }
    }

    return coordinates;
  }
};
