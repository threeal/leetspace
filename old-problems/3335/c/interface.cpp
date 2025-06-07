#include <string>

extern "C" {
int lengthAfterTransformations(char* s, int t);
}

int solution_c(std::string s, int t) {
  return lengthAfterTransformations(s.data(), t);
}
