#include <string>

extern "C" {
char* minimizeResult(char* expression);
}

std::string solution_c(std::string expression) {
  return minimizeResult(expression.data());
}
