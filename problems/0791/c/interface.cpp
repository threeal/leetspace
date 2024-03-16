#include <string>

extern "C" {
char* customSortString(char* order, char* s);
}

std::string solution_c(std::string order, std::string s) {
  return customSortString(order.data(), s.data());
}
