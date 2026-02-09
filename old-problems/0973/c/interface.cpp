#include <cstring>
#include <vector>

extern "C" {
int** kClosest(
    int** points, int pointsSize, int* pointsColSize, int k,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<std::vector<int>> points, int k) {
  std::vector<int*> pointsDatas(points.size());
  std::vector<int> pointsSizes(points.size());
  for (std::size_t i{0}; i < points.size(); ++i) {
    pointsDatas[i] = points[i].data();
    pointsSizes[i] = points[i].size();
  }

  int returnSize{};
  int* returnColumnSizes{};
  int** returnData{
      kClosest(
          pointsDatas.data(), points.size(), pointsSizes.data(), k,
          &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], output[i].size() * sizeof(int));
  }

  return output;
}
