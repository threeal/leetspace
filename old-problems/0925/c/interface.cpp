#include <string>

extern "C" {
bool isLongPressedName(char* name, char* typed);
}

bool solution_c(std::string name, std::string typed) {
  return isLongPressedName(name.data(), typed.data());
}
