#include <stdlib.h>

int compare(const void* a, const void* b) {
  const int* aa = *(int**)a;
  const int* bb = *(int**)b;
  return aa[0] == bb[0] ? aa[1] - bb[1] : aa[0] - bb[0];
}

int numEquivDominoPairs(
    int** dominoes, int dominoesSize, int* dominoesColSize) {
  (void)dominoesColSize;

  for (int i = 0; i < dominoesSize; ++i) {
    if (dominoes[i][0] > dominoes[i][1]) {
      const int temp = dominoes[i][0];
      dominoes[i][0] = dominoes[i][1];
      dominoes[i][1] = temp;
    };
  }

  qsort(dominoes, dominoesSize, sizeof(int*), compare);

  int totalPairs = 0, pairs = 0;
  for (int i = 1; i < dominoesSize; ++i) {
    if (dominoes[i][0] == dominoes[i - 1][0] &&
        dominoes[i][1] == dominoes[i - 1][1]) {
      ++pairs;
    } else {
      if (pairs > 0) totalPairs += (pairs * (pairs + 1)) / 2;
      pairs = 0;
    }
  }

  if (pairs > 0) totalPairs += (pairs * (pairs + 1)) / 2;
  return totalPairs;
}
