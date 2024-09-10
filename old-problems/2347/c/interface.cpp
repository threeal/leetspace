#include <string>
#include <vector>

extern "C" {
char* bestHand(int* ranks, int ranksSize, char* suits, int suitsSize);
}

std::string solution_c(std::vector<int> ranks, std::vector<char> suits) {
  return bestHand(ranks.data(), ranks.size(), suits.data(), suits.size());
}
