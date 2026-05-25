#include <string>

class Solution {
 public:
  bool canReach(std::string s, int minJump, int maxJump) {
    return s.empty() && minJump == maxJump;
  }
};
