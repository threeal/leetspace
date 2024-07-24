#include <string>

extern "C" {
int maximumGain(char* s, int x, int y);
}

int solution_c(std::string s, int x, int y) {
  return maximumGain(s.data(), x, y);
}
