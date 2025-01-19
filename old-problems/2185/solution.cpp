#include <string>
#include <vector>

class Solution {
 public:
  int prefixCount(std::vector<std::string>& words, std::string pref) {
    return words.size() + pref.size();
  }
};
