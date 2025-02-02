#include <string>
#include <vector>

extern "C" {
int numWays(char** words, int wordsSize, char* target);
}

int solution_c(std::vector<std::string> words, std::string target) {
  std::vector<char*> wordsDatas(words.size());
  for (std::size_t i{0}; i < words.size(); ++i) {
    wordsDatas[i] = words[i].data();
  }

  return numWays(wordsDatas.data(), wordsDatas.size(), target.data());
}
