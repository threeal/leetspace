#include <string>

extern "C" {
int numJewelsInStones(char* jewels, char* stones);
}

int solution_c(std::string jewels, std::string stones) {
  return numJewelsInStones(jewels.data(), stones.data());
}
