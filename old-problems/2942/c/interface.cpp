#include <cstring>
#include <string>
#include <vector>

extern "C" {
int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize);
}

std::vector<int> solution_c(std::vector<std::string> words, char x) {
  std::vector<char*> wordsDatas(words.size());
  for (std::size_t i{0}; i < words.size(); ++i) {
    wordsDatas[i] = words[i].data();
  }

  int returnSize{};
  int* returnData{
      findWordsContaining(wordsDatas.data(), words.size(), x, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
