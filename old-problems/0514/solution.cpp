#include <string>

class Solution {
 public:
  int findRotateSteps(std::string ring, std::string key) {
    return ring.size() + key.size();
  }
};
