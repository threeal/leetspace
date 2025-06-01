#include <vector>

extern "C" {
int minTimeToReach(int** moveTime, int moveTimeSize, int* moveTimeColSize);
}

int solution_c(std::vector<std::vector<int>> moveTime) {
  std::vector<int*> moveTimeDatas(moveTime.size());
  std::vector<int> moveTimeSizes(moveTime.size());
  for (std::size_t i{0}; i < moveTime.size(); ++i) {
    moveTimeDatas[i] = moveTime[i].data();
    moveTimeSizes[i] = moveTime[i].size();
  }

  return minTimeToReach(
      moveTimeDatas.data(), moveTime.size(), moveTimeSizes.data());
}
