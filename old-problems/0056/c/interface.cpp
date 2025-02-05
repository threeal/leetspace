#include <cstring>
#include <vector>

extern "C" {
int** merge(
    int** intervals, int intervalsSize, int* intervalsColSize,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<std::vector<int>> intervals) {
  std::vector<int*> intervalsDatas(intervals.size());
  std::vector<int> intervalsSizes(intervals.size());
  for (std::size_t i{0}; i < intervals.size(); ++i) {
    intervalsDatas[i] = intervals[i].data();
    intervalsSizes[i] = intervals[i].size();
  }

  int returnSize;
  int* returnColumnSizes;
  int** returnData = merge(
      intervalsDatas.data(), intervalsDatas.size(), intervalsSizes.data(),
      &returnSize, &returnColumnSizes);

  std::vector<std::vector<int>> output(returnSize);
  for (int i{0}; i < returnSize; ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], sizeof(int) * returnColumnSizes[i]);
  }

  return output;
}
