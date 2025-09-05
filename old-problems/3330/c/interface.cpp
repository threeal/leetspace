#include <string>

extern "C" {
int possibleStringCount(char* word);
}

int solution_c(std::string target) {
  return possibleStringCount(target.data());
}
