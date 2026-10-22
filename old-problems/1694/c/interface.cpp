#include <cstdlib>
#include <cstring>
#include <string>

extern "C" {
char* reformatNumber(char* number);
}

std::string solution_c(std::string number) {
  char* data = static_cast<char*>(malloc((number.size() + 1) * sizeof(char)));
  memcpy(data, number.data(), (number.size() + 1) * sizeof(char));
  return reformatNumber(data);
}
