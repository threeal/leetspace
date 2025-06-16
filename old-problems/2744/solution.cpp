#include <string>
#include <vector>

class Solution {
 public:
  int maximumNumberOfStringPairs(std::vector<std::string>& words) {
    int count{0};
    for (std::size_t j{1}; j < words.size(); ++j) {
      for (std::size_t i{0}; i < j; ++i) {
        if (words[i][0] == words[j][1] && words[i][1] == words[j][0]) ++count;
      }
    }
    return count;
  }
};
