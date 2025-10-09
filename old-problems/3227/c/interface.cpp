#include <string>

extern "C" {
bool doesAliceWin(char* s);
}

bool solution_c(std::string s) {
  return doesAliceWin(s.data());
}
