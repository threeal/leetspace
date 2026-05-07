#include <vector>

extern "C" {
long long largestSquareArea(
    int** bottomLeft, int bottomLeftSize, int* bottomLeftColSize,
    int** topRight, int topRightSize, int* topRightColSize);
}

long long solution_c(
    std::vector<std::vector<int>> bottomLeft,
    std::vector<std::vector<int>> topRight) {
  std::vector<int*> bottomLeftDatas(bottomLeft.size());
  std::vector<int> bottomLeftSizes(bottomLeft.size());
  for (std::size_t i{0}; i < bottomLeft.size(); ++i) {
    bottomLeftDatas[i] = bottomLeft[i].data();
    bottomLeftSizes[i] = bottomLeft[i].size();
  }

  std::vector<int*> topRightDatas(topRight.size());
  std::vector<int> topRightSizes(topRight.size());
  for (std::size_t i{0}; i < topRight.size(); ++i) {
    topRightDatas[i] = topRight[i].data();
    topRightSizes[i] = topRight[i].size();
  }

  return largestSquareArea(
      bottomLeftDatas.data(), bottomLeft.size(), bottomLeftSizes.data(),
      topRightDatas.data(), topRight.size(), topRightSizes.data());
}
