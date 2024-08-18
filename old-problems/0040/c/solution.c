#include <stdlib.h>
#include <string.h>

void fillCombinations(
    int* maxCombinationsSize, int*** combinations,
    int* combinationsSize, int** combinationsColumnSizes,
    int* current, int currentSize,
    int* candidates, int candidatesSize,
    int target);

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int** combinationSum2(
    int* candidates, int candidatesSize, int target,
    int* returnSize, int** returnColumnSizes) {
  qsort(candidates, candidatesSize, sizeof(int), compare);

  int maxCombinationsSize = 8;
  int** combinations = malloc(maxCombinationsSize * sizeof(int*));

  *returnSize = 0;
  *returnColumnSizes = malloc(maxCombinationsSize * sizeof(int));

  int* current = malloc(candidatesSize * sizeof(int));
  int currentSize = 0;

  fillCombinations(
      &maxCombinationsSize, &combinations,
      returnSize, returnColumnSizes,
      current, currentSize,
      candidates, candidatesSize,
      target);

  free(current);

  return combinations;
}

void fillCombinations(
    int* maxCombinationsSize, int*** combinations,
    int* combinationsSize, int** combinationsColumnSizes,
    int* current, int currentSize,
    int* candidates, int candidatesSize,
    int target) {
  int prevCandidate = 0;
  for (int i = 0; i < candidatesSize; ++i) {
    if (candidates[i] > target) break;

    if (candidates[i] == prevCandidate) continue;
    prevCandidate = candidates[i];

    current[currentSize] = candidates[i];
    ++currentSize;
    if (candidates[i] == target) {
      if (*combinationsSize >= *maxCombinationsSize) {
        *maxCombinationsSize *= 8;
        const int size = *maxCombinationsSize * sizeof(int*);
        *combinations = realloc(*combinations, size);
        *combinationsColumnSizes = realloc(*combinationsColumnSizes, size);
      }

      const int size = currentSize * sizeof(int);
      (*combinations)[*combinationsSize] = malloc(size);
      memcpy((*combinations)[*combinationsSize], current, size);

      (*combinationsColumnSizes)[*combinationsSize] = currentSize;

      ++(*combinationsSize);
    } else {
      fillCombinations(
          maxCombinationsSize, combinations,
          combinationsSize, combinationsColumnSizes,
          current, currentSize,
          candidates + i + 1, candidatesSize - i - 1,
          target - candidates[i]);
    }
    --currentSize;
  }
}
