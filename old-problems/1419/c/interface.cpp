#include <string>

extern "C" {
int minNumberOfFrogs(char* croakOfFrogs);
}

int solution_c(std::string croakOfFrogs) {
  return minNumberOfFrogs(croakOfFrogs.data());
}
