#include <string>

extern "C" {
char* interpret(char* command);
}

std::string solution_c(std::string command) {
  return interpret(command.data());
}
