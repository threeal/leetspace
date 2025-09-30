#include <vector>

extern "C" {
int areaOfMaxDiagonal(
    int** dimensions, int dimensionsSize, int* dimensionsColSize);
}

int solution_c(std::vector<std::vector<int>> dimensions) {
  std::vector<int*> dimensionsDatas(dimensions.size());
  std::vector<int> dimensionsSizes(dimensions.size());
  for (std::size_t i{0}; i < dimensions.size(); ++i) {
    dimensionsDatas[i] = dimensions[i].data();
    dimensionsSizes[i] = dimensions[i].size();
  }

  return areaOfMaxDiagonal(
      dimensionsDatas.data(), dimensions.size(), dimensionsSizes.data());
}
