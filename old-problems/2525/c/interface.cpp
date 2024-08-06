#include <string>

extern "C" {
char* categorizeBox(int length, int width, int height, int mass);
}

std::string solution_c(int length, int width, int height, int mass) {
  return categorizeBox(length, width, height, mass);
}
