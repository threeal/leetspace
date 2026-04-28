#include <vector>

extern "C" {
bool hasAllCodes(char* s, int k);
}

bool solution_c(std::string s, int k) {
  return hasAllCodes(s.data(), k);
}
