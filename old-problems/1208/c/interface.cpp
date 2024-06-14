#include <string>

extern "C" {
int equalSubstring(char* s, char* t, int maxCost);
}

int solution_c(std::string s, std::string t, int maxCost) {
  return equalSubstring(s.data(), t.data(), maxCost);
}
