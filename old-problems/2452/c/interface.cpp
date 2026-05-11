#include <vector>

extern "C" {
char** twoEditWords(
    char** queries, int queriesSize, char** dictionary, int dictionarySize,
    int* returnSize);
}

std::vector<std::string> solution_c(
    std::vector<std::string> queries, std::vector<std::string> dictionary) {
  std::vector<char*> queriesDatas(queries.size());
  for (std::size_t i{0}; i < queries.size(); ++i) {
    queriesDatas[i] = queries[i].data();
  }

  std::vector<char*> dictionaryDatas(dictionary.size());
  for (std::size_t i{0}; i < dictionary.size(); ++i) {
    dictionaryDatas[i] = dictionary[i].data();
  }

  int returnSize{};
  char** returnData{twoEditWords(
      queriesDatas.data(), queries.size(),
      dictionaryDatas.data(), dictionary.size(), &returnSize)};

  std::vector<std::string> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i] = returnData[i];
  }

  return output;
}
