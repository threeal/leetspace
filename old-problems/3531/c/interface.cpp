#include <vector>

extern "C" {
int countCoveredBuildings(
    int n, int** buildings, int buildingsSize, int* buildingsColSize);
}

int solution_c(int n, std::vector<std::vector<int>> buildings) {
  std::vector<int*> buildingsDatas(buildings.size());
  std::vector<int> buildingsSizes(buildings.size());
  for (std::size_t i{0}; i < buildings.size(); ++i) {
    buildingsDatas[i] = buildings[i].data();
    buildingsSizes[i] = buildings[i].size();
  }

  return countCoveredBuildings(
      n, buildingsDatas.data(), buildings.size(), buildingsSizes.data());
}
