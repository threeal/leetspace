#include <cstring>
#include <vector>

extern "C" {
int** queensAttacktheKing(
    int** queens, int queensSize, int* queensColSize, int* king, int kingSize,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<std::vector<int>> queens, std::vector<int> king) {
  std::vector<int*> queensDatas(queens.size());
  std::vector<int> queensSizes(queens.size());
  for (std::size_t i{0}; i < queens.size(); ++i) {
    queensDatas[i] = queens[i].data();
    queensSizes[i] = queens[i].size();
  }

  int returnSize{};
  int* returnColumnSizes{};
  int** returnData{
      queensAttacktheKing(
          queensDatas.data(), queens.size(), queensSizes.data(),
          king.data(), king.size(), &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
