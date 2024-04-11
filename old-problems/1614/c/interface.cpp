#include <string>

extern "C" {
int maxDepth(char* s);
}

int solution_c(std::string s) {
  return maxDepth(s.data());
}
