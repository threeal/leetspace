#include <queue>
#include <vector>

class Solution {
 public:
  int shortestBridge(std::vector<std::vector<int>>& grid) {
    const int n = grid.size();
    for (int i{n - 1}; i >= 0; --i) {
      for (int j{n - 1}; j >= 0; --j) {
        if (grid[i][j] == 0) continue;

        std::queue<int> lands{};
        std::queue<int> seas{};

        // Explore the first island and find the neighboring seas.
        grid[i][j] = 2;
        lands.push(i << 7 | j);
        while (!lands.empty()) {
          const int i{lands.front() >> 7};
          const int j{lands.front() & 0b1111111};

          if (i > 0 && grid[i - 1][j] >= 0) {
            if (grid[i - 1][j] == 0) {
              seas.push((i - 1) << 7 | j);
            } else {
              lands.push((i - 1) << 7 | j);
            }
            grid[i - 1][j] = -1;
          }

          if (j > 0 && grid[i][j - 1] >= 0) {
            if (grid[i][j - 1] == 0) {
              seas.push(i << 7 | (j - 1));
            } else {
              lands.push(i << 7 | (j - 1));
            }
            grid[i][j - 1] = -1;
          }

          if (i + 1 < n && grid[i + 1][j] >= 0) {
            if (grid[i + 1][j] == 0) {
              seas.push((i + 1) << 7 | j);
            } else {
              lands.push((i + 1) << 7 | j);
            }
            grid[i + 1][j] = -1;
          }

          if (j + 1 < n && grid[i][j + 1] >= 0) {
            if (grid[i][j + 1] == 0) {
              seas.push(i << 7 | (j + 1));
            } else {
              lands.push(i << 7 | (j + 1));
            }
            grid[i][j + 1] = -1;
          }

          lands.pop();
        }

        // Explore the sea until it reaches the next island.
        for (int distance{1}; !seas.empty(); ++distance) {
          for (std::size_t k{seas.size()}; k > 0; --k) {
            const int i{seas.front() >> 7};
            const int j{seas.front() & 0b1111111};

            if (i > 0 && grid[i - 1][j] >= 0) {
              if (grid[i - 1][j] == 1) return distance;
              seas.push((i - 1) << 7 | j);
              grid[i - 1][j] = -1;
            }

            if (j > 0 && grid[i][j - 1] >= 0) {
              if (grid[i][j - 1] == 1) return distance;
              seas.push(i << 7 | (j - 1));
              grid[i][j - 1] = -1;
            }

            if (i + 1 < n && grid[i + 1][j] >= 0) {
              if (grid[i + 1][j] == 1) return distance;
              seas.push((i + 1) << 7 | j);
              grid[i + 1][j] = -1;
            }

            if (j + 1 < n && grid[i][j + 1] >= 0) {
              if (grid[i][j + 1] == 1) return distance;
              seas.push(i << 7 | (j + 1));
              grid[i][j + 1] = -1;
            }
            seas.pop();
          }
        }

        return 0;
      }
    }
    return 0;
  }
};
