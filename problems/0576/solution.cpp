#include <functional>
#include <unordered_map>
#include <vector>

#define MOD 1000000007

class Solution {
 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    auto cache = std::vector(m, std::vector<std::unordered_map<int, int>>(n));

    const std::function<int(int, int, int)> fn = [&](int x, int y, int move) -> int {
      if (move == 0) return 0;

      auto it = cache[x][y].find(move);
      if (it == cache[x][y].end()) {
        int count = x > 0 ? fn(x - 1, y, move - 1) : 1;
        count = (count + (y > 0 ? fn(x, y - 1, move - 1) : 1)) % MOD;
        count = (count + (x < m - 1 ? fn(x + 1, y, move - 1) : 1)) % MOD;
        count = (count + (y < n - 1 ? fn(x, y + 1, move - 1) : 1)) % MOD;
        it = cache[x][y].emplace(move, count).first;
      }

      return it->second;
    };

    return fn(startRow, startColumn, maxMove);
  }
};
