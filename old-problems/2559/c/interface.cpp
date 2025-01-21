#include <cstring>
#include <string>
#include <vector>

extern "C" {
int* vowelStrings(
    char** words, int wordsSize,
    int** queries, int queriesSize, int* queriesColSize, int* returnSize);
}

std::vector<int> solution_c(
    std::vector<std::string> words, std::vector<std::vector<int>> queries) {
  std::vector<char*> wordsDatas(words.size());
  for (std::size_t i{0}; i < words.size(); ++i) {
    wordsDatas[i] = words[i].data();
  }

  std::vector<int*> queriesDatas(queries.size());
  std::vector<int> queriesSizes(queries.size());
  for (std::size_t i{0}; i < queries.size(); ++i) {
    queriesDatas[i] = queries[i].data();
    queriesSizes[i] = queries[i].size();
  }

  int returnSize{};
  int* returnData = vowelStrings(
      wordsDatas.data(), wordsDatas.size(),
      queriesDatas.data(), queriesDatas.size(), queriesSizes.data(),
      &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
