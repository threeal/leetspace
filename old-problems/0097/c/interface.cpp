#include <string>

extern "C" {
bool isInterleave(char* s1, char* s2, char* s3);
}

bool solution_c(std::string s1, std::string s2, std::string s3) {
  return isInterleave(s1.data(), s2.data(), s3.data());
}
