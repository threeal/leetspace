#include <vector>

extern "C" {
int minGroups(int** intervals, int intervalsSize, int* intervalsColSize);
}

int solution_c(std::vector<std::vector<int>> intervals) {
  std::vector<int*> intervalsDatas(intervals.size());
  std::vector<int> intervalsSizes(intervals.size());
  for (std::size_t i{0}; i < intervals.size(); ++i) {
    intervalsDatas[i] = intervals[i].data();
    intervalsSizes[i] = intervals[i].size();
  }

  return minGroups(
      intervalsDatas.data(), intervalsDatas.size(), intervalsSizes.data());
}
