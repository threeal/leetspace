#include <string>

extern "C" {
int titleToNumber(char* columnTitle);
}

int solution_c(std::string columnTitle) {
  return titleToNumber(columnTitle.data());
}
