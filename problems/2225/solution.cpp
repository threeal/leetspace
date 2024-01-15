#include <set>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
    std::set<int> allPlayers;
    std::unordered_map<int, int> lossesCounts;

    for (const auto& match : matches) {
      allPlayers.insert(match[0]);
      allPlayers.insert(match[1]);

      ++lossesCounts[match[1]];
    }

    std::vector<std::vector<int>> results(2);
    for (const auto player : allPlayers) {
      const auto it = lossesCounts.find(player);
      if (it == lossesCounts.end()) {
        results[0].push_back(player);
      } else if (it->second == 1) {
        results[1].push_back(player);
      }
    }

    return results;
  }
};
