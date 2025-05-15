#include <vector>

extern "C" {
int numEquivDominoPairs(
    int** dominoes, int dominoesSize, int* dominoesColSize);
}

int solution_c(std::vector<std::vector<int>> dominoes) {
  std::vector<int*> dominoesDatas(dominoes.size());
  std::vector<int> dominoesSizes(dominoes.size());
  for (std::size_t i{0}; i < dominoes.size(); ++i) {
    dominoesDatas[i] = dominoes[i].data();
    dominoesSizes[i] = dominoes[i].size();
  }

  return numEquivDominoPairs(
      dominoesDatas.data(), dominoes.size(), dominoesSizes.data());
}
