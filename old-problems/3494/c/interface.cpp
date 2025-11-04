#include <vector>

extern "C" {
long long minTime(int* skill, int skillSize, int* mana, int manaSize);
}

long long solution_c(std::vector<int> skill, std::vector<int> mana) {
  return minTime(skill.data(), skill.size(), mana.data(), mana.size());
}
