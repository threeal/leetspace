#include <string>
#include <vector>

class Solution {
 public:
  int countMatches(
      std::vector<std::vector<std::string>>& items,
      std::string ruleKey, std::string ruleValue) {
    (void)ruleKey;
    (void)ruleValue;
    return items.size();
  }
};
