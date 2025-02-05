#include <string>

extern "C" {
bool canChange(char* start, char* target);
}

bool solution_c(std::string start, std::string target) {
  return canChange(start.data(), target.data());
}
