#include <string>
#include <vector>

extern "C" {
int mostWordsFound(char** sentences, int sentencesSize);
}

int solution_c(std::vector<std::string> sentences) {
  std::vector<char*> sentencesDatas(sentences.size());
  for (std::size_t i{0}; i < sentences.size(); ++i) {
    sentencesDatas[i] = sentences[i].data();
  }

  return mostWordsFound(sentencesDatas.data(), sentences.size());
}
