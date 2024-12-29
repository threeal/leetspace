#include <string>
#include <vector>

class Solution {
 public:
  int numWays(std::vector<std::string>& words, std::string target) {
    return words.size() * target.size();;
  }
};
