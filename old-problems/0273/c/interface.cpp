#include <string>

extern "C" {
char* numberToWords(int num);
}

std::string solution_c(int num) {
  return numberToWords(num);
}
