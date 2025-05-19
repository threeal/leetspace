#include <string>
#include <vector>

extern "C" {
char* restoreString(char* s, int* indices, int indicesSize);
}

std::string solution_c(std::string s, std::vector<int> indices) {
  return restoreString(s.data(), indices.data(), indices.size());
}
