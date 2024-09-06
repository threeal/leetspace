#include <vector>

extern "C" {
bool isCovered(
    int** ranges, int rangesSize, int* rangesColSize, int left, int right);
}

bool solution_c(std::vector<std::vector<int>> ranges, int left, int right) {
  std::vector<int*> rangesDatas(ranges.size());
  std::vector<int> rangesSizes(ranges.size());
  for (int i = ranges.size() - 1; i >= 0; --i) {
    rangesDatas[i] = ranges[i].data();
    rangesSizes[i] = ranges[i].size();
  }

  return isCovered(
      rangesDatas.data(), rangesDatas.size(), rangesSizes.data(), left, right);
}
