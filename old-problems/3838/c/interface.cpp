#include <string>
#include <vector>

extern "C" {
char* mapWordWeights(
    char** words, int wordsSize, int* weights, int weightsSize);
}

std::string solution_c(
    std::vector<std::string> words, std::vector<int> weights) {
  std::vector<char*> wordsDatas(words.size());
  for (std::size_t i{0}; i < words.size(); ++i) {
    wordsDatas[i] = words[i].data();
  }
  return mapWordWeights(
      wordsDatas.data(), words.size(), weights.data(), weights.size());
}
