#include <string>

extern "C" {
int partitionString(char* s);
}

int solution_c(std::string s) {
  return partitionString(s.data());
}
