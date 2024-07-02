#include <cstring>
#include <string>
#include <vector>

extern "C" {
int* numSmallerByFrequency(char** queries, int queriesSize, char** words, int wordsSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<std::string> queries, std::vector<std::string> words) {
  std::vector<char*> queriesDatas(queries.size());
  for (int i = queries.size() - 1; i >= 0; --i) {
    queriesDatas[i] = queries[i].data();
  }

  std::vector<char*> wordsDatas(words.size());
  for (int i = words.size() - 1; i >= 0; --i) {
    wordsDatas[i] = words[i].data();
  }

  int returnSize{};
  const int* returnData{numSmallerByFrequency(queriesDatas.data(), queriesDatas.size(), wordsDatas.data(), wordsDatas.size(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
