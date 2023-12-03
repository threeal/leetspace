#include <string>
#include <vector>

extern "C" {
int countCharacters(char** words, int wordsSize, char* chars);
}

int solution_c(std::vector<std::string> words, std::string chars) {
  std::vector<char*> wordsData(words.size());
  for (std::size_t i = 0; i < words.size(); ++i) {
    wordsData[i] = words[i].data();
  }

  return countCharacters(wordsData.data(), wordsData.size(), chars.data());
}
