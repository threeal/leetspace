#include <string>

extern "C" {
char* complexNumberMultiply(char* num1, char* num2);
}

std::string solution_c(std::string num1, std::string num2) {
  return complexNumberMultiply(num1.data(), num2.data());
}
