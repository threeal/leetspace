#include <string>

extern "C" {
bool areSentencesSimilar(char* sentence1, char* sentence2);
}

int solution_c(std::string sentence1, std::string sentence2) {
  return areSentencesSimilar(sentence1.data(), sentence2.data());
}
