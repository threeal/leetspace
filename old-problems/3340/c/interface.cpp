#include <string>

extern "C" {
bool isBalanced(char* num);
}

bool solution_c(std::string num) {
  return isBalanced(num.data());
}
