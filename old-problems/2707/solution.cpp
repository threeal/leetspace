#include <string>
#include <vector>

class Solution {
 public:
  int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
    return s.size() - dictionary.size();
  }
};
