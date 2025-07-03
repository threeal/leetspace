#include <string>
#include <vector>

extern "C" {
char** getWordsInLongestSubsequence(
    char** words, int wordsSize, int* groups, int groupsSize, int* returnSize);
}

std::vector<std::string> solution_c(
    std::vector<std::string> words, std::vector<int> groups) {
  std::vector<char*> wordsDatas(words.size());
  for (std::size_t i{0}; i < words.size(); ++i) {
    wordsDatas[i] = words[i].data();
  }

  int returnSize{};
  char** returnData{
      getWordsInLongestSubsequence(
          wordsDatas.data(), words.size(), groups.data(), groups.size(),
          &returnSize)};

  std::vector<std::string> output(returnSize);
  for (int i{0}; i < returnSize; ++i) {
    output[i] = returnData[i];
  }

  return output;
}
