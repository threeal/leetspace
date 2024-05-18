#include <string>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
    std::vector<std::string> ranks(score.size());
    std::vector<std::pair<int, std::string*>> scoreRanks(score.size());
    for (std::size_t i{0}; i < scoreRanks.size(); ++i) {
      scoreRanks[i].first = score[i];
      scoreRanks[i].second = ranks.data() + i;
    }

    std::sort(scoreRanks.begin(), scoreRanks.end(), std::greater<std::pair<int, std::string*>>());
    if (scoreRanks.size() > 0) *scoreRanks[0].second = "Gold Medal";
    if (scoreRanks.size() > 1) *scoreRanks[1].second = "Silver Medal";
    if (scoreRanks.size() > 2) *scoreRanks[2].second = "Bronze Medal";
    for (std::size_t i{3}; i < scoreRanks.size(); ++i) {
      *scoreRanks[i].second = std::to_string(i + 1);
    }

    return ranks;
  }
};
