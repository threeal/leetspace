#include <cstdint>
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

    std::vector<std::int16_t> queue(1500);
    std::size_t queueBegin{0};
    std::size_t queueEnd{1};
    queue[queueBegin] = 0;
    seen[0] = true;

    int steps{1};
    int target{std::stoi(targetStr)};
    while (queueBegin != queueEnd) {
      for (std::size_t i{(queueBegin < queueEnd ? queueEnd : 1500 + queueEnd) - queueBegin}; i > 0; --i) {
        for (std::int16_t exp{1}; exp <= 1000; exp *= 10) {
          auto key{queue[queueBegin]};
          key += (key / exp) % 10 == 9 ? -9 * exp : exp;
          if (key == target) return steps;
          if (!seen[key]) {
            queue[queueEnd] = key;
            if (++queueEnd == 1500) queueEnd = 0;
            seen[key] = true;
          }

          key = queue[queueBegin];
          key += (key / exp) % 10 == 0 ? 9 * exp : -exp;
          if (key == target) return steps;
          if (!seen[key]) {
            queue[queueEnd] = key;
            if (++queueEnd == 1500) queueEnd = 0;
            seen[key] = true;
          }
        }
        if (++queueBegin == 1500) queueBegin = 0;
      }
      ++steps;
    }

    return -1;
  }
};
