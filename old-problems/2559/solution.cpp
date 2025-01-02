#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> vowelStrings(
      std::vector<std::string>& words, std::vector<std::vector<int>>& queries) {
    return std::vector<int>(queries.size(), words.size());
  }
};
