#include <string>

extern "C" {
int minLengthAfterRemovals(char* s);
}

int solution_c(std::string s) {
  return minLengthAfterRemovals(s.data());
}
