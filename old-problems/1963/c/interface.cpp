#include <string>

extern "C" {
int minSwaps(char* s);
}

int solution_c(std::string s) {
  return minSwaps(s.data());
}
