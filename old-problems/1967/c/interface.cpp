#include <string>
#include <vector>

extern "C" {
int numOfStrings(char** patterns, int patternsSize, char* word);
}

int solution_c(std::vector<std::string> patterns, std::string word) {
  std::vector<char*> patternsDatas(patterns.size());
  for (std::size_t i{0}; i < patterns.size(); ++i) {
    patternsDatas[i] = patterns[i].data();
  }

  return numOfStrings(patternsDatas.data(), patterns.size(), word.data());
}
