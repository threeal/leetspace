#include <string>

extern "C" {
bool digitCount(char* num);
}

bool solution_c(std::string num) {
  return digitCount(num.data());
}
