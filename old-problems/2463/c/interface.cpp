#include <vector>

extern "C" {
long long minimumTotalDistance(
    int* robot, int robotSize,
    int** factory, int factorySize, int* factoryColSize);
}

long long solution_c(
    std::vector<int> robot, std::vector<std::vector<int>> factory) {
  std::vector<int*> factoryDatas(factory.size());
  std::vector<int> factorySizes(factory.size());
  for (std::size_t i{0}; i < factory.size(); ++i) {
    factoryDatas[i] = factory[i].data();
    factorySizes[i] = factory[i].size();
  }

  return minimumTotalDistance(
      robot.data(), robot.size(),
      factoryDatas.data(), factoryDatas.size(), factorySizes.data());
}
