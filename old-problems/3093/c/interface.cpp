#include <cstring>
#include <string>
#include <vector>

extern "C" {
int* stringIndices(
    char** wordsContainer, int wordsContainerSize,
    char** wordsQuery, int wordsQuerySize, int* returnSize);
}

std::vector<int> solution_c(
    std::vector<std::string> wordsContainer,
    std::vector<std::string> wordsQuery) {
  std::vector<char*> wordsContainerDatas(wordsContainer.size());
  for (std::size_t i{0}; i < wordsContainer.size(); ++i) {
    wordsContainerDatas[i] = wordsContainer[i].data();
  }

  std::vector<char*> wordsQueryDatas(wordsQuery.size());
  for (std::size_t i{0}; i < wordsQuery.size(); ++i) {
    wordsQueryDatas[i] = wordsQuery[i].data();
  }

  int returnSize{};
  int* returnData{
      stringIndices(
          wordsContainerDatas.data(), wordsContainer.size(),
          wordsQueryDatas.data(), wordsQuery.size(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, output.size() * sizeof(int));

  return output;
}
