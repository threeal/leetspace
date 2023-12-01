#include <string>
#include <vector>

extern "C" {
bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size);
}

bool solution_c(std::vector<std::string> word1, std::vector<std::string> word2) {
  std::vector<char*> word1Ptrs(word1.size());
  for (std::size_t i = 0; i < word1.size(); ++i) {
    word1Ptrs[i] = word1[i].data();
  }

  std::vector<char*> word2Ptrs(word2.size());
  for (std::size_t i = 0; i < word2.size(); ++i) {
    word2Ptrs[i] = word2[i].data();
  }

  return arrayStringsAreEqual(word1Ptrs.data(), word1Ptrs.size(), word2Ptrs.data(), word2Ptrs.size());
}
