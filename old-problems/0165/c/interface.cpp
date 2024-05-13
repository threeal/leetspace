#include <string>

extern "C" {
int compareVersion(char* version1, char* version2);
}

int solution_c(std::string version1, std::string version2) {
  return compareVersion(version1.data(), version2.data());
}
