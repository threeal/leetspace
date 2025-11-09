#include <cstring>
#include <vector>

extern "C" {
int** pacificAtlantic(
    int** heights, int heightsSize, int* heightsColSize,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<std::vector<int>> heights) {
  std::vector<int*> heightsDatas(heights.size());
  std::vector<int> heightsSizes(heights.size());

  for (std::size_t i{0}; i < heights.size(); ++i) {
    heightsDatas[i] = heights[i].data();
    heightsSizes[i] = heights[i].size();
  }

  int returnSize{};
  int* returnColumnSizes{};
  int** returnData{
      pacificAtlantic(
          heightsDatas.data(), heights.size(), heightsSizes.data(),
          &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], output[i].size() * sizeof(int));
  }

  return output;
}
