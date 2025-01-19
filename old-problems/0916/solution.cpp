#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> wordSubsets(
      std::vector<std::string>& words1, std::vector<std::string>& words2) {
    words1.insert(words1.end(), words2.begin(), words2.end());
    return words1;
  }
};
