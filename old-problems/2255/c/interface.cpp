#include <string>
#include <vector>

extern "C" {
int countPrefixes(char** words, int wordsSize, char* s);
}

int solution_c(std::vector<std::string> words, std::string s) {
  std::vector<char*> wordsDatas(words.size());
  for (std::size_t i{0}; i < words.size(); ++i) {
    wordsDatas[i] = words[i].data();
  }

  return countPrefixes(wordsDatas.data(), wordsDatas.size(), s.data());
}
