#include <vector>

extern "C" {
long long dividePlayers(int* skill, int skillSize);
}

long long solution_c(std::vector<int> skill) {
  return dividePlayers(skill.data(), skill.size());
}
