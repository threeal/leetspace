#include <stdlib.h>

long long minTime(int* skill, int skillSize, int* mana, int manaSize) {
  const int doneSize = skillSize + 1;
  long long* done = malloc(doneSize * sizeof(long long));
  for (int i = 0; i < doneSize; ++i) done[i] = 0;

  for (int i = 0; i < manaSize; ++i) {
    const long long m = mana[i];
    for (int j = 0; j < skillSize; ++j) {
      done[j + 1] = (done[j + 1] >= done[j] ? done[j + 1] : done[j]) + m * skill[j];
    }
    for (int j = skillSize - 1; j > 0; --j) {
      done[j] = done[j + 1] - m * skill[j];
    }
  }

  const long long res = done[skillSize];
  free(done);

  return res;
}
