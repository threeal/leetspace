#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int* fairCandySwap(
    int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize,
    int* returnSize) {
  *returnSize = 2;
  int* output = malloc(2 * sizeof(int));

  qsort(aliceSizes, aliceSizesSize, sizeof(int), compare);
  qsort(bobSizes, bobSizesSize, sizeof(int), compare);

  int aliceSum = 0;
  for (int i = aliceSizesSize - 1; i >= 0; --i) {
    aliceSum += aliceSizes[i];
  }

  int bobSum = 0;
  for (int i = bobSizesSize - 1; i >= 0; --i) {
    bobSum += bobSizes[i];
  }

  if (aliceSum <= bobSum) {
    const int diff = (bobSum - aliceSum) / 2;
    int* bobBegin = bobSizes;
    for (int i = 0; i < aliceSizesSize; ++i) {
      int* bobEnd = bobSizes + bobSizesSize;
      while (bobBegin < bobEnd) {
        int* bobIt = bobBegin + (bobEnd - bobBegin) / 2;
        if (*bobIt < aliceSizes[i] + diff) {
          bobBegin = bobIt + 1;
        } else {
          bobEnd = bobIt;
        }
      }

      if (aliceSizes[i] + diff == *bobBegin) {
        output[0] = aliceSizes[i];
        output[1] = *bobBegin;
        return output;
      }
    }
  } else {
    const int diff = (aliceSum - bobSum) / 2;
    int* aliceBegin = aliceSizes;
    for (int i = 0; i < bobSizesSize; ++i) {
      int* aliceEnd = aliceSizes + aliceSizesSize;
      while (aliceBegin < aliceEnd) {
        int* aliceIt = aliceBegin + (aliceEnd - aliceBegin) / 2;
        if (*aliceIt < bobSizes[i] + diff) {
          aliceBegin = aliceIt + 1;
        } else {
          aliceEnd = aliceIt;
        }
      }

      if (bobSizes[i] + diff == *aliceBegin) {
        output[0] = *aliceBegin;
        output[1] = bobSizes[i];
        return output;
      }
    }
  }

  return output;
}
