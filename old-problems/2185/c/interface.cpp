#include <string>
#include <vector>

extern "C" {
int prefixCount(char** words, int wordsSize, char* pref);
}

int solution_c(std::vector<std::string> words, std::string pref) {
  std::vector<char*> wordsDatas(words.size());
  for (std::size_t i{0}; i < words.size(); ++i) {
    wordsDatas[i] = words[i].data();
  }

  return prefixCount(wordsDatas.data(), wordsDatas.size(), pref.data());
}
