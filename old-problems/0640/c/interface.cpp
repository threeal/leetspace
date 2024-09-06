#include <string>

extern "C" {
char* solveEquation(char* equation);
}

std::string solution_c(std::string equation) {
  return solveEquation(equation.data());
}
