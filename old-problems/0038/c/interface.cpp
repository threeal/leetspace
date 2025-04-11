#include <string>

extern "C" {
char* countAndSay(int n);
}

std::string solution_c(int n) {
  return countAndSay(n);
}
