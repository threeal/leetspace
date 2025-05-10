#include <cstring>
#include <vector>

extern "C" {
int* countPoints(
    int** points, int pointsSize, int* pointsColSize,
    int** queries, int queriesSize, int* queriesColSize, int* returnSize);
}

std::vector<int> solution_c(
    std::vector<std::vector<int>> points,
    std::vector<std::vector<int>> queries) {
  std::vector<int*> pointsDatas(points.size());
  std::vector<int> pointsSizes(points.size());
  for (std::size_t i{0}; i < points.size(); ++i) {
    pointsDatas[i] = points[i].data();
    pointsSizes[i] = points[i].size();
  }

  std::vector<int*> queriesDatas(queries.size());
  std::vector<int> queriesSizes(queries.size());
  for (std::size_t i{0}; i < queries.size(); ++i) {
    queriesDatas[i] = queries[i].data();
    queriesSizes[i] = queries[i].size();
  }

  int returnSize{};
  int* returnData{
      countPoints(
          pointsDatas.data(), points.size(), pointsSizes.data(),
          queriesDatas.data(), queries.size(), queriesSizes.data(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
