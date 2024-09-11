#include <stdlib.h>

int* gAliceValues;
int* gBobValues;

int compare(const void* a, const void* b) {
  return gAliceValues[*(int*)a] + gBobValues[*(int*)a] <
      gAliceValues[*(int*)b] + gBobValues[*(int*)b];
}

int stoneGameVI(
    int* aliceValues, int aliceValuesSize, int* bobValues, int bobValuesSize) {
  (void)bobValuesSize;

  int* indices = malloc(aliceValuesSize * sizeof(int));
  for (int i = 0; i < aliceValuesSize; ++i) indices[i] = i;

  gAliceValues = aliceValues;
  gBobValues = bobValues;
  qsort(indices, aliceValuesSize, sizeof(int), compare);

  int alice = 0;
  for (int i = 0; i < aliceValuesSize; i += 2) {
    alice += aliceValues[indices[i]];
  }

  int bob = 0;
  for (int i = 1; i < aliceValuesSize; i += 2) {
    bob += bobValues[indices[i]];
  }

  return alice == bob ? 0 : (alice > bob ? 1 : -1);
}
