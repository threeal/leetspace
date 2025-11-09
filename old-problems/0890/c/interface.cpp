#include <cstring>
#include <string>
#include <vector>

extern "C" {
char** findAndReplacePattern(
    char** words, int wordsSize, char* pattern, int* returnSize);
}

std::vector<std::string> solution_c(
    std::vector<std::string> words, std::string pattern) {
  std::vector<char*> wordsDatas(words.size());
  for (std::size_t i{0}; i < words.size(); ++i) {
    wordsDatas[i] = words[i].data();
  }

  int returnSize{};
  char** returnData{
      findAndReplacePattern(
          wordsDatas.data(), words.size(), pattern.data(), &returnSize)};

  std::vector<std::string> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i] = returnData[i];
  }

  return output;
}
