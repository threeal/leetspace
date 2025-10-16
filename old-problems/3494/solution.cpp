#include <algorithm>
#include <vector>

class Solution {
 public:
  long long minTime(std::vector<int>& skill, std::vector<int>& mana) {
    std::vector<long long> done(skill.size() + 1, 0);
    for (const int m : mana) {
      const long long mm = m;
      for (std::size_t i{0}; i < skill.size(); ++i) {
        done[i + 1] = std::max<long long>(done[i + 1], done[i]) + mm * skill[i];
      }
      for (std::size_t i{skill.size() - 1}; i > 0; --i) {
        done[i] = done[i + 1] - mm * skill[i];
      }
    }
    return done[skill.size()];
  }
};
