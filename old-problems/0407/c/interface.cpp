#include <vector>

extern "C" {
int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize);
}

int solution_c(std::vector<std::vector<int>> heightMap) {
  std::vector<int*> heightMapDatas(heightMap.size());
  std::vector<int> heightMapSizes(heightMap.size());
  for (std::size_t i{0}; i < heightMap.size(); ++i) {
    heightMapDatas[i] = heightMap[i].data();
    heightMapSizes[i] = heightMap[i].size();
  }

  return trapRainWater(
      heightMapDatas.data(), heightMap.size(), heightMapSizes.data());
}
