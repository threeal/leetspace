#include <algorithm>
#include <vector>

class Solution {
 public:
  long long dividePlayers(std::vector<int>& skill) {
    std::sort(skill.begin(), skill.end());
    const int teamSkill{skill.front() + skill.back()};

    long long chemistry{0};
    for (std::size_t l{0}, r{skill.size() - 1}; l < r; ++l, --r) {
      if (skill[l] + skill[r] != teamSkill) return -1;
      chemistry += skill[l] * skill[r];
    }

    return chemistry;
  }
};
