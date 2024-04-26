#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int openLock(std::vector<std::string>& deadends, std::string target) {
    if (target == "0000") return 0;

    std::unordered_set<std::string> seen(deadends.begin(), deadends.end());
    if (seen.contains("0000")) return -1;

    std::queue<std::string> queue{};
    queue.push("0000");
    seen.insert("0000");

    int steps{1};
    while (!queue.empty()) {
      for (std::size_t i{queue.size()}; i > 0; --i) {
        for (int i = 0; i < 4; ++i) {
          auto key{queue.front()};
          key[i] = key[i] == '9' ? '0' : key[i] + 1;
          if (key == target) return steps;
          if (!seen.contains(key)) {
            queue.push(key);
            seen.insert(key);
          }

          key = queue.front();
          key[i] = key[i] == '0' ? '9' : key[i] - 1;
          if (key == target) return steps;
          if (!seen.contains(key)) {
            queue.push(key);
            seen.insert(key);
          }
        }
        queue.pop();
      }
      ++steps;
    }

    return -1;
  }
};
