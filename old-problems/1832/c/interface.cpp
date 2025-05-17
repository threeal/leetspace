#include <string>

extern "C" {
bool checkIfPangram(char* sentence);
}

bool solution_c(std::string sentence) {
  return checkIfPangram(sentence.data());
}
