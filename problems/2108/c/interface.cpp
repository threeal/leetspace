#include <string>
#include <vector>

extern "C" {
char* firstPalindrome(char** words, int wordsSize);
}

std::string solution_c(std::vector<std::string> words) {
  std::vector<char*> wordsData(words.size());
  for (std::size_t i = 0; i < words.size(); ++i) {
    wordsData[i] = words[i].data();
  }

  return firstPalindrome(wordsData.data(), wordsData.size());
}
