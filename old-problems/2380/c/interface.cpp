#include <string>

extern "C" {
int secondsToRemoveOccurrences(char* s);
}

int solution_c(std::string s) {
  return secondsToRemoveOccurrences(s.data());
}
