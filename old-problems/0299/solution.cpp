#include <string>

class Solution {
 public:
  std::string getHint(std::string secret, std::string guess) {
    return secret + guess;
  }
};
