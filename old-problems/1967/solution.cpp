#include <string>
#include <vector>

class Solution {
 public:
  int numOfStrings(std::vector<std::string>& patterns, std::string word) {
    int count{0};
    for (const std::string& pattern : patterns) {
      if (word.find(pattern) != std::string::npos) ++count;
    }
    return count;
  }
};
