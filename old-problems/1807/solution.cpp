#include <string>
#include <vector>

class Solution {
 public:
  std::string evaluate(
      std::string s, std::vector<std::vector<std::string>>& knowledge) {
    return s + knowledge.front().front();
  }
};
