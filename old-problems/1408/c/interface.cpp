#include <string>
#include <vector>

extern "C" {
char** stringMatching(char** words, int wordsSize, int* returnSize);
}

std::vector<std::string> solution_c(std::vector<std::string> words) {
  std::vector<char*> wordsDatas(words.size());
  for (std::size_t i = 0; i < words.size(); ++i) {
    wordsDatas[i] = words[i].data();
  }

  int returnSize{};
  char** returnData = stringMatching(
      wordsDatas.data(), wordsDatas.size(), &returnSize);

  std::vector<std::string> output(returnSize);
  for (std::size_t i = 0; i < output.size(); ++i) {
    output[i] = returnData[i];
  }

  return output;
}
