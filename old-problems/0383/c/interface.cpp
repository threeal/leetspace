#include <string>

extern "C" {
bool canConstruct(char* ransomNote, char* magazine);
}

bool solution_c(std::string ransomNote, std::string magazine) {
  return canConstruct(ransomNote.data(), magazine.data());
}
