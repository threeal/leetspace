#include <string>

extern "C" {
int maxDistinct(char* s);
}

int solution_c(std::string s) {
  return maxDistinct(s.data());
}
