#include <string>
#include <vector>

class Solution {
 public:
  int numOfStrings(std::vector<std::string>& patterns, std::string word) {
    return word.size() + patterns.size();
  }
};
