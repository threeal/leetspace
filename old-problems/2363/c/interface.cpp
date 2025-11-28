#include <cstring>
#include <vector>

extern "C" {
int** mergeSimilarItems(
    int** items1, int items1Size, int* items1ColSize,
    int** items2, int items2Size, int* items2ColSize,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<std::vector<int>> items1,
    std::vector<std::vector<int>> items2) {
  std::vector<int*> items1Datas(items1.size());
  std::vector<int> items1Sizes(items1.size());
  for (std::size_t i{0}; i < items1.size(); ++i) {
    items1Datas[i] = items1[i].data();
    items1Sizes[i] = items1[i].size();
  }

  std::vector<int*> items2Datas(items2.size());
  std::vector<int> items2Sizes(items2.size());
  for (std::size_t i{0}; i < items2.size(); ++i) {
    items2Datas[i] = items2[i].data();
    items2Sizes[i] = items2[i].size();
  }

  int returnSize{};
  int* returnColumnSizes{};
  int** returnData{
      mergeSimilarItems(
          items1Datas.data(), items1.size(), items1Sizes.data(),
          items2Datas.data(), items2.size(), items2Sizes.data(),
          &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
