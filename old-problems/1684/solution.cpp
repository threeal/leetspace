#include <string>
#include <vector>

class Solution {
 public:
  int countConsistentStrings(
      std::string allowed, std::vector<std::string>& words) {
    return words.size() - allowed.size();
  }
};
