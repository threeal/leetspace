#include <string>
#include <vector>

extern "C" {
int countPrefixSuffixPairs(char** words, int wordsSize);
}

int solution_c(std::vector<std::string> words) {
  std::vector<char*> wordsDatas(words.size());
  for (std::size_t i{0}; i < words.size(); ++i) {
    wordsDatas[i] = words[i].data();
  }

  return countPrefixSuffixPairs(wordsDatas.data(), wordsDatas.size());
}
