#include <string>
#include <vector>

class Solution {
 public:
  int countWords(
      std::vector<std::string>& words1, std::vector<std::string>& words2) {
    return words1.size() + words2.size();
  }
};
