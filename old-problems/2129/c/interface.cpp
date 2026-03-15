#include <string>

extern "C" {
char* capitalizeTitle(char* title);
}

std::string solution_c(std::string title) {
  return capitalizeTitle(title.data());
}
