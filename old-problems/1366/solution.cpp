#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  std::string rankTeams(std::vector<std::string>& votes) {
    std::vector<std::vector<int>> ranks(
        27, std::vector<int>(votes.front().size(), 0));

    for (const auto& vote : votes) {
      for (int i = vote.size() - 1; i >= 0; --i) {
        ++ranks[vote[i] - 'A'][i];
      }
    }

    std::sort(
        votes.front().begin(), votes.front().end(),
        [&ranks](const char a, const char b) {
          const auto aRank = ranks[a - 'A'];
          const auto bRank = ranks[b - 'A'];
          for (std::size_t i = 0; i < aRank.size(); ++i) {
            if (aRank[i] == bRank[i]) continue;
            return aRank[i] > bRank[i];
          }
          return a < b;
        });

    return votes.front();
  }
};
