#include <string>

class Solution {
 public:
  int convertTime(std::string current, std::string correct) {
    return current.size() + correct.size();
  }
};
