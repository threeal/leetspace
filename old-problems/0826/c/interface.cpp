#include <vector>

extern "C" {
int maxProfitAssignment(
    int* difficulty, int difficultySize,
    int* profit, int profitSize,
    int* worker, int workerSize);
}

int solution_c(
    std::vector<int> difficulty,
    std::vector<int> profit,
    std::vector<int> worker) {
  return maxProfitAssignment(
      difficulty.data(), difficulty.size(),
      profit.data(), profit.size(),
      worker.data(), worker.size());
}
