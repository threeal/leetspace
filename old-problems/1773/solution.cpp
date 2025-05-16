#include <string>
#include <vector>

class Solution {
 public:
  int countMatches(
      std::vector<std::vector<std::string>>& items,
      std::string ruleKey, std::string ruleValue) {
    int count{0};
    int i{ruleKey[0] == 't' ? 0 : (ruleKey[0] == 'c' ? 1 : 2)};
    for (const std::vector<std::string>& item : items) {
      if (item[i] == ruleValue) ++count;
    }
    return count;
  }
};
