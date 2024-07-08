#include <string>

class Solution {
 public:
  int minNumberOfFrogs(std::string croakOfFrogs) {
    return croakOfFrogs.size() / 5;
  }
};
