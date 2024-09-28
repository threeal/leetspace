#include <string>
#include <vector>

extern "C" {
int countConsistentStrings(char* allowed, char** words, int wordsSize);
}

int solution_c(std::string allowed, std::vector<std::string> words) {
  std::vector<char*> wordsDatas{};
  wordsDatas.reserve(words.size());
  for (auto& word : words) {
    wordsDatas.push_back(word.data());
  }

  return countConsistentStrings(
      allowed.data(), wordsDatas.data(), wordsDatas.size());
}
