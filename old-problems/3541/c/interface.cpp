#include <string>

extern "C" {
int maxFreqSum(char* s);
}

int solution_c(std::string s) {
  return maxFreqSum(s.data());
}
