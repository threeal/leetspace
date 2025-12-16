#include <cstring>
#include <vector>

extern "C" {
int** highestPeak(
    int** isWater, int isWaterSize, int* isWaterColSize,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<std::vector<int>> isWater) {
  std::vector<int*> isWaterDatas(isWater.size());
  std::vector<int> isWaterSizes(isWater.size());
  for (std::size_t i{0}; i < isWater.size(); ++i) {
    isWaterDatas[i] = isWater[i].data();
    isWaterSizes[i] = isWater[i].size();
  }

  int returnSize{};
  int* returnColumnSizes{};
  int** returnData{
      highestPeak(
          isWaterDatas.data(), isWater.size(), isWaterSizes.data(),
          &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], output[i].size() * sizeof(int));
  }

  return output;
}
