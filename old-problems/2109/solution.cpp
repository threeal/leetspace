#include <string>
#include <vector>

class Solution {
 public:
  std::string addSpaces(std::string s, std::vector<int>& spaces) {
    s.resize(s.size() + spaces.size(), ' ');
    return s;
  }
};
