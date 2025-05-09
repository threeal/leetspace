#include <cstring>
#include <vector>

extern "C" {
int** groupThePeople(
    int* groupSizes, int groupSizesSize,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(std::vector<int> groupSizes) {
  int returnSize{};
  int* returnColumnSizes{};
  int** returnData{
      groupThePeople(
          groupSizes.data(), groupSizes.size(),
          &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> output(returnSize);
  for (int i{0}; i < returnSize; ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
