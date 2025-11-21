#include <string>

class Solution {
 public:
  int minFlips(std::string target) {
    std::size_t i{0}, count{0};
    while (true) {
      while (i < target.size() && target[i] == '0') ++i;
      if (i == target.size()) break;
      ++count;

      while (i < target.size() && target[i] == '1') ++i;
      if (i == target.size()) break;
      ++count;
    }
    return count;
  }
};
