#include <string>

extern "C" {
bool canReach(char* s, int minJump, int maxJump);
}

bool solution_c(std::string s, int minJump, int maxJump) {
  return canReach(s.data(), minJump, maxJump);
}
