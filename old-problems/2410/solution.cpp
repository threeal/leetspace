#include <vector>

class Solution {
 public:
  int matchPlayersAndTrainers(
      std::vector<int>& players, std::vector<int>& trainers) {
    return players.front() + trainers.front();
  }
};
