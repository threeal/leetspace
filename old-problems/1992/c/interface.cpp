#include <cstring>
#include <vector>

extern "C" {
int** findFarmland(int** land, int landSize, int* landColSize, int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(std::vector<std::vector<int>> land) {
  std::vector<int*> landDatas(land.size());
  std::vector<int> landSizes(land.size());
  for (std::size_t i{0}; i < land.size(); ++i) {
    landDatas[i] = land[i].data();
    landSizes[i] = land[i].size();
  }

  int returnSize;
  int* returnColumnSizes;
  const auto returnData = findFarmland(landDatas.data(), landDatas.size(), landSizes.data(), &returnSize, &returnColumnSizes);

  std::vector<std::vector<int>> output(returnSize);
  for (int i{0}; i < returnSize; ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
