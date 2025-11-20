#include <vector>

extern "C" {
int maximumUnits(
    int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize);
}

int solution_c(std::vector<std::vector<int>> boxTypes, int truckSize) {
  std::vector<int*> boxTypesDatas(boxTypes.size());
  std::vector<int> boxTypesSizes(boxTypes.size());
  for (std::size_t i{0}; i < boxTypes.size(); ++i) {
    boxTypesDatas[i] = boxTypes[i].data();
    boxTypesSizes[i] = boxTypes[i].size();
  }

  return maximumUnits(
      boxTypesDatas.data(), boxTypes.size(), boxTypesSizes.data(), truckSize);
}
