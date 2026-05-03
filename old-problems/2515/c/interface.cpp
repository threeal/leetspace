#include <vector>

extern "C" {
int closestTarget(char** words, int wordsSize, char* target, int startIndex);
}

int solution_c(
    std::vector<std::string> words, std::string target, int startIndex) {
  std::vector<char*> wordsDatas(words.size());
  for (std::size_t i{0}; i < words.size(); ++i) {
    wordsDatas[i] = words[i].data();
  }

  return closestTarget(
      wordsDatas.data(), words.size(), target.data(), startIndex);
}
