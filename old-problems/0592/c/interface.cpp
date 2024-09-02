#include <string>

extern "C" {
char* fractionAddition(char* expression);
}

std::string solution_c(std::string expression) {
  return fractionAddition(expression.data());
}
