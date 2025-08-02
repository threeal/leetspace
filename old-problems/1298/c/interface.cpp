#include <cstring>
#include <vector>

extern "C" {
int maxCandies(
    int* status, int statusSize,
    int* candies, int candiesSize,
    int** keys, int keysSize, int* keysColSize,
    int** containedBoxes, int containedBoxesSize, int* containedBoxesColSize,
    int* initialBoxes, int initialBoxesSize);
}

int solution_c(
    std::vector<int> status,
    std::vector<int> candies,
    std::vector<std::vector<int>> keys,
    std::vector<std::vector<int>> containedBoxes,
    std::vector<int> initialBoxes) {
  std::vector<int*> keysDatas(keys.size());
  std::vector<int> keysSizes(keys.size());
  for (std::size_t i{0}; i < keys.size(); ++i) {
    keysDatas[i] = keys[i].data();
    keysSizes[i] = keys[i].size();
  }

  std::vector<int*> containedBoxesDatas(containedBoxes.size());
  std::vector<int> containedBoxesSizes(containedBoxes.size());
  for (std::size_t i{0}; i < containedBoxes.size(); ++i) {
    containedBoxesDatas[i] = containedBoxes[i].data();
    containedBoxesSizes[i] = containedBoxes[i].size();
  }

  return maxCandies(
      status.data(), status.size(),
      candies.data(), candies.size(),
      keysDatas.data(), keys.size(), keysSizes.data(),
      containedBoxesDatas.data(), containedBoxes.size(),
      containedBoxesSizes.data(),
      initialBoxes.data(), initialBoxes.size());
}
