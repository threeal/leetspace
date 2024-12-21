#include <string>
#include <vector>

extern "C" {
char* addSpaces(char* s, int* spaces, int spacesSize);
}

std::string solution_c(std::string s, std::vector<int> spaces) {
  return addSpaces(s.data(), spaces.data(), spaces.size());
}
