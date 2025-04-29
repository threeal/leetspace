#include <string>

extern "C" {
char* defangIPaddr(char* address);
}

std::string solution_c(std::string address) {
  return defangIPaddr(address.data());
}
