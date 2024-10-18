#include <vector>

extern "C" {
int findCircleNum(
    int** isConnected, int isConnectedSize, int* isConnectedColSize);
}

int solution_c(std::vector<std::vector<int>> isConnected) {
  std::vector<int*> isConnectedDatas(isConnected.size());
  std::vector<int> isConnectedSizes(isConnected.size());
  for (std::size_t i{0}; i < isConnected.size(); ++i) {
    isConnectedDatas[i] = isConnected[i].data();
    isConnectedSizes[i] = isConnected[i].size();
  }

  return findCircleNum(
      isConnectedDatas.data(), isConnectedDatas.size(),
      isConnectedSizes.data());
}
