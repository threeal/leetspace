#include <vector>

extern "C" {
long long maximumImportance(
    int n, int** roads, int roadsSize, int* roadsColSize);
}

long long solution_c(int n, std::vector<std::vector<int>> roads) {
  std::vector<int*> roadsDatas(roads.size());
  std::vector<int> roadsSizes(roads.size());
  for (int i = roads.size() - 1; i >= 0; --i) {
    roadsDatas[i] = roads[i].data();
    roadsSizes[i] = roads[i].size();
  }

  return maximumImportance(
      n, roadsDatas.data(), roadsDatas.size(), roadsSizes.data());
}
