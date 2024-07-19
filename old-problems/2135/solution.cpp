#include <string>
#include <vector>

class Solution {
 public:
  int wordCount(
      std::vector<std::string>& startWords,
      std::vector<std::string>& targetWords) {
    return startWords.size() * targetWords.size();
  }
};
