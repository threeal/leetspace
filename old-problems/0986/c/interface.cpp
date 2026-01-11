#include <cstring>
#include <vector>

extern "C" {
int** intervalIntersection(
    int** firstList, int firstListSize, int* firstListColSize,
    int** secondList, int secondListSize, int* secondListColSize,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<std::vector<int>> firstList, std::vector<std::vector<int>> secondList) {
  std::vector<int*> firstListDatas(firstList.size());
  std::vector<int> firstListSizes(firstList.size());
  for (std::size_t i{0}; i < firstList.size(); ++i) {
    firstListDatas[i] = firstList[i].data();
    firstListSizes[i] = firstList[i].size();
  }

  std::vector<int*> secondListDatas(secondList.size());
  std::vector<int> secondListSizes(secondList.size());
  for (std::size_t i{0}; i < secondList.size(); ++i) {
    secondListDatas[i] = secondList[i].data();
    secondListSizes[i] = secondList[i].size();
  }

  int returnSize{};
  int* returnColumnSizes{};
  int** returnData{
      intervalIntersection(
          firstListDatas.data(), firstList.size(), firstListSizes.data(),
          secondListDatas.data(), secondList.size(), secondListSizes.data(),
          &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], output[i].size() * sizeof(int));
  }

  return output;
}
