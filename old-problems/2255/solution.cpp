#include <string>
#include <vector>

class Solution {
 public:
  int countPrefixes(std::vector<std::string>& words, std::string s) {
    return words.size() + s.size();
  }
};
