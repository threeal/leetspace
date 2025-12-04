#include <string>
#include <vector>

extern "C" {
int numSpecialEquivGroups(char** words, int wordsSize);
}

int solution_c(std::vector<std::string> words) {
  std::vector<char*> wordsDatas(words.size());
  for (std::size_t i{0}; i < words.size(); ++i) {
    wordsDatas[i] = words[i].data();
  }

  return numSpecialEquivGroups(wordsDatas.data(), words.size());
}
