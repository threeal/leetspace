#include <cstring>
#include <vector>

extern "C" {
int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> deck) {
  int returnSize{};
  int* returnData{deckRevealedIncreasing(deck.data(), deck.size(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, output.size() * sizeof(int));

  return output;
}
