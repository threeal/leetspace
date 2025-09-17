#include <vector>

extern "C" {
bool judgePoint24(int* cards, int cardsSize);
}

bool solution_c(std::vector<int> cards) {
  return judgePoint24(cards.data(), cards.size());
}
