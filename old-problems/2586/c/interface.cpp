#include <vector>

extern "C" {
int vowelStrings(char** words, int wordsSize, int left, int right);
}

int solution_c(std::vector<std::string> words, int left, int right) {
  std::vector<char*> wordsDatas(words.size());
  for (std::size_t i{0}; i < words.size(); ++i) {
    wordsDatas[i] = words[i].data();
  }

  return vowelStrings(wordsDatas.data(), words.size(), left, right);
}
