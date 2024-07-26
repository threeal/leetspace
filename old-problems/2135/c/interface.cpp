#include <string>
#include <vector>

extern "C" {
int wordCount(
    char** startWords, int startWordsSize,
    char** targetWords, int targetWordsSize);
}

int solution_c(
    std::vector<std::string> startWords, std::vector<std::string> targetWords) {
  std::vector<char*> startWordsDatas(startWords.size());
  for (int i = startWords.size() - 1; i >= 0; --i) {
    startWordsDatas[i] = startWords[i].data();
  }

  std::vector<char*> targetWordsDatas(targetWords.size());
  for (int i = targetWords.size() - 1; i >= 0; --i) {
    targetWordsDatas[i] = targetWords[i].data();
  }

  return wordCount(
      startWordsDatas.data(), startWordsDatas.size(),
      targetWordsDatas.data(), targetWordsDatas.size());
}
