#include <string>
#include <vector>

class Solution {
 public:
  int closestTarget(
      std::vector<std::string>& words, std::string target, int startIndex) {
    return words.size() + target.size() + startIndex;
  }
};
