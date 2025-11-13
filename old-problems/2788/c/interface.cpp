#include <string>
#include <vector>

extern "C" {
char** splitWordsBySeparator(
    char** words, int wordsSize, char separator, int* returnSize);
}

std::vector<std::string> solution_c(
    std::vector<std::string> words, char separator) {
  std::vector<char*> wordsDatas(words.size());
  for (std::size_t i{0}; i < words.size(); ++i) {
    wordsDatas[i] = words[i].data();
  }

  int returnSize{};
  char** returnData{
      splitWordsBySeparator(
          wordsDatas.data(), words.size(), separator, &returnSize)};

  std::vector<std::string> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i] = returnData[i];
  }

  return output;
}
