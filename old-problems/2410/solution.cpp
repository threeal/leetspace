#include <algorithm>
#include <vector>

class Solution {
 public:
  int matchPlayersAndTrainers(
      std::vector<int>& players, std::vector<int>& trainers) {
    std::sort(players.begin(), players.end());
    std::sort(trainers.begin(), trainers.end());

    std::size_t i{0}, j{0};
    while (i < players.size() && j < trainers.size()) {
      while (j < trainers.size() && players[i] > trainers[j]) ++j;
      if (j < trainers.size()) ++i, ++j;
    }

    return i;
  }
};
