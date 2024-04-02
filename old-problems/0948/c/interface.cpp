#include <vector>

extern "C" {
int bagOfTokensScore(int* tokens, int tokensSize, int power);
}

int solution_c(std::vector<int> tokens, int power) {
  return bagOfTokensScore(tokens.data(), tokens.size(), power);
}
