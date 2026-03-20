#include <string>

extern "C" {
char* digitSum(char* s, int k);
}

std::string solution_c(std::string s, int k) {
  return digitSum(s.data(), k);
}
