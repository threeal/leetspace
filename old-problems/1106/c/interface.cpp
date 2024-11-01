#include <string>

extern "C" {
bool parseBoolExpr(char* expression);
}

bool solution_c(std::string expression) {
  return parseBoolExpr(expression.data());
}
