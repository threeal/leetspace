#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

long long dividePlayers(int* skill, int skillSize) {
  qsort(skill, skillSize, sizeof(int), compare);
  const int teamSkill = skill[0] + skill[skillSize - 1];

  long long chemistry = 0;
  for (int l = 0, r = skillSize - 1; l < r; ++l, --r) {
    if (skill[l] + skill[r] != teamSkill) return -1;
    chemistry += skill[l] * skill[r];
  }

  return chemistry;
}
