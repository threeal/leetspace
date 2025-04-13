#include <vector>

extern "C" {
bool hasGroupsSizeX(int* deck, int deckSize);
}

bool solution_c(std::vector<int> deck) {
  return hasGroupsSizeX(deck.data(), deck.size());
}
