#include <string>

extern "C" {
long long minimumSteps(char* s);
}

long long solution_c(std::string s) {
  return minimumSteps(s.data());
}
