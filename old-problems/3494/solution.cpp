#include <vector>

class Solution {
 public:
  long long minTime(std::vector<int>& skill, std::vector<int>& mana) {
    return skill.size() + mana.size();
  }
};
