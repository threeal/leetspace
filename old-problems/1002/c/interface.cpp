#include <cstring>
#include <string>
#include <vector>

extern "C" {
char** commonChars(char** words, int wordsSize, int* returnSize);
}

std::vector<std::string> solution_c(std::vector<std::string> words) {
  std::vector<char*> wordsDatas(words.size());
  for (int i = words.size() - 1; i >= 0; --i) {
    wordsDatas[i] = words[i].data();
  }

  int returnSize{};
  char** returnData{commonChars(wordsDatas.data(), wordsDatas.size(), &returnSize)};

  std::vector<std::string> output(returnSize);
  for (int i = returnSize - 1; i >= 0; --i) {
    output[i].resize(std::strlen(returnData[i]));
    std::strcpy(output[i].data(), returnData[i]);
  }

  return output;
}
