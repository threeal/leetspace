#include <cstring>
#include <string>
#include <vector>

extern "C" {
char** wordSubsets(
    char** words1, int words1Size,
    char** words2, int words2Size, int* returnSize);
}

std::vector<std::string> solution_c(
    std::vector<std::string> words1, std::vector<std::string> words2) {
  std::vector<char*> words1Datas(words1.size());
  for (std::size_t i{0}; i < words1.size(); ++i) {
    words1Datas[i] = words1[i].data();
  }

  std::vector<char*> words2Datas(words2.size());
  for (std::size_t i{0}; i < words2.size(); ++i) {
    words2Datas[i] = words2[i].data();
  }

  int returnSize{};
  char** returnData = wordSubsets(
      words1Datas.data(), words1Datas.size(),
      words2Datas.data(), words2Datas.size(), &returnSize);

  std::vector<std::string> output(returnSize);
  for (int i{0}; i < returnSize; ++i) {
    output[i] = returnData[i];
  }

  return output;
}
