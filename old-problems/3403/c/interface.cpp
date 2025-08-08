#include <string>

extern "C" {
char* answerString(char* word, int numFriends);
}

std::string solution_c(std::string word, int numFriends) {
  return answerString(word.data(), numFriends);
}
