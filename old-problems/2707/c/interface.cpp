#include <string>
#include <vector>

extern "C" {
int minExtraChar(char* s, char** dictionary, int dictionarySize);
}

int solution_c(std::string s, std::vector<std::string> dictionary) {
  std::vector<char*> dictionaryDatas(dictionary.size());
  for (std::size_t i{0}; i < dictionary.size(); ++i) {
    dictionaryDatas[i] = dictionary[i].data();
  }

  return minExtraChar(s.data(), dictionaryDatas.data(), dictionaryDatas.size());
}
