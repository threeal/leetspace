#include <queue>
#include <string>
#include <vector>

class Solution {
 public:
  int openLock(std::vector<std::string>& deadends, std::string targetStr) {
    if (targetStr == "0000") return 0;

    std::vector<bool> seen(10000, false);
    for (const auto& deadend : deadends) {
      seen[std::stoi(deadend)] = true;
    }

    if (seen[0]) return -1;

    std::queue<int> queue{};
    queue.push(0);
    seen[0] = true;

    int steps{1};
    int target{std::stoi(targetStr)};
    while (!queue.empty()) {
      for (std::size_t i{queue.size()}; i > 0; --i) {
        for (int exp{1}; exp <= 1000; exp *= 10) {
          auto key{queue.front()};
          key += (key / exp) % 10 == 9 ? -9 * exp : exp;
          if (key == target) return steps;
          if (!seen[key]) {
            queue.push(key);
            seen[key] = true;
          }

          key = queue.front();
          key += (key / exp) % 10 == 0 ? 9 * exp : -exp;
          if (key == target) return steps;
          if (!seen[key]) {
            queue.push(key);
            seen[key] = true;
          }
        }
        queue.pop();
      }
      ++steps;
    }

    return -1;
  }
};
