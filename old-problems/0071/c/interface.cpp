#include <string>

extern "C" {
char* simplifyPath(char* path);
}

std::string solution_c(std::string path) {
  return simplifyPath(path.data());
}
