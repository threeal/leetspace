#include <string>

extern "C" {
bool isAnagram(char* s, char* t);
}

bool solution_c(std::string s, std::string t) {
  return isAnagram(s.data(), t.data());
}
