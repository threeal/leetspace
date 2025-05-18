#include <string>

extern "C" {
char* decodeMessage(char* key, char* message);
}

std::string solution_c(std::string key, std::string message) {
  return decodeMessage(key.data(), message.data());
}
