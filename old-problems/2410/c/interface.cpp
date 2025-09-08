#include <vector>

extern "C" {
int matchPlayersAndTrainers(
    int* players, int playersSize, int* trainers, int trainersSize);
}

int solution_c(std::vector<int> players, std::vector<int> trainers) {
  return matchPlayersAndTrainers(
      players.data(), players.size(), trainers.data(), trainers.size());
}
