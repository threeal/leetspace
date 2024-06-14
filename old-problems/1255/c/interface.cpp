#include <string>
#include <vector>

extern "C" {
int maxScoreWords(char** words, int wordsSize, char* letters, int lettersSize, int* score, int scoreSize);
}

int solution_c(std::vector<std::string> words, std::vector<char> letters, std::vector<int> score) {
  std::vector<char*> wordsDatas(words.size());
  for (int i = words.size() - 1; i >= 0; --i) {
    wordsDatas[i] = words[i].data();
  }

  return maxScoreWords(wordsDatas.data(), wordsDatas.size(), letters.data(), letters.size(), score.data(), score.size());
}
