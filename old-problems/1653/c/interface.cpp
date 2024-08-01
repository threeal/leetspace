#include <string>

extern "C" {
int minimumDeletions(char* s);
}

int solution_c(std::string s) {
  return minimumDeletions(s.data());
}
