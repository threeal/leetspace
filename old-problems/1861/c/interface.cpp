#include <cstring>
#include <vector>

extern "C" {
char** rotateTheBox(
    char** boxGrid, int boxGridSize, int* boxGridColSize,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<char>> solution_c(
    std::vector<std::vector<char>> boxGrid) {
  std::vector<char*> boxGridDatas(boxGrid.size());
  std::vector<int> boxGridSizes(boxGrid.size());
  for (std::size_t i{0}; i < boxGrid.size(); ++i) {
    boxGridDatas[i] = boxGrid[i].data();
    boxGridSizes[i] = boxGrid[i].size();
  }

  int returnSize{};
  int* returnColumnSizes{};
  char** returnData = rotateTheBox(
      boxGridDatas.data(), boxGridDatas.size(), boxGridSizes.data(),
      &returnSize, &returnColumnSizes);

  std::vector<std::vector<char>> output(returnSize);
  for (int i{0}; i < returnSize; ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(char));
  }

  return output;
}
