#include <vector>

extern "C" {
int maxDistance(int** arrays, int arraysSize, int* arraysColSize);
}

int solution_c(std::vector<std::vector<int>> arrays) {
  std::vector<int*> arraysDatas(arrays.size());
  std::vector<int> arraysSizes(arrays.size());
  for (int i = arrays.size() - 1; i >= 0; --i) {
    arraysDatas[i] = arrays[i].data();
    arraysSizes[i] = arrays[i].size();
  }

  return maxDistance(
      arraysDatas.data(), arraysDatas.size(), arraysSizes.data());
}
