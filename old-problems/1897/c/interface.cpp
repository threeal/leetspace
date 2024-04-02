#include <string>
#include <vector>

extern "C" {
bool makeEqual(char** words, int wordsSize);
}

int solution_c(std::vector<std::string> words) {
  std::vector<char*> words_data(words.size());
  for (std::size_t i = 0; i < words_data.size(); ++i) {
    words_data[i] = words[i].data();
  }

  return makeEqual(words_data.data(), words_data.size());
}
