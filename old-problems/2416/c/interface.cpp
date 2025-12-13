#include <cstring>
#include <string>
#include <vector>

extern "C" {
int* sumPrefixScores(char** words, int wordsSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<std::string> words) {
  std::vector<char*> wordsDatas(words.size());
  for (std::size_t i{0}; i < words.size(); ++i) {
    wordsDatas[i] = words[i].data();
  }

  int returnSize{};
  const auto returnData = sumPrefixScores(
      wordsDatas.data(), wordsDatas.size(), &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
