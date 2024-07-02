#include <string>
#include <vector>

extern "C" {
char* replaceWords(char** dictionary, int dictionarySize, char* sentence);
}

std::string solution_c(std::vector<std::string> dictionary, std::string sentence) {
  std::vector<char*> dictionaryDatas(dictionary.size());
  for (int i = dictionary.size() - 1; i >= 0; --i) {
    dictionaryDatas[i] = dictionary[i].data();
  }

  return replaceWords(dictionaryDatas.data(), dictionaryDatas.size(), sentence.data());
}
