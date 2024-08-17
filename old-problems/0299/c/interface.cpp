#include <string>

extern "C" {
char* getHint(char* secret, char* guess);
}

std::string solution_c(std::string secret, std::string guess) {
  return getHint(secret.data(), guess.data());
}
