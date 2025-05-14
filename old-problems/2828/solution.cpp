#include <string>
#include <vector>

class Solution {
 public:
  bool isAcronym(std::vector<std::string>& words, std::string s) {
    return words.size() == s.size();
  }
};
