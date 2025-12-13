#include <string>

extern "C" {
int beautySum(char* s);
}

int solution_c(std::string s) {
  return beautySum(s.data());
}
