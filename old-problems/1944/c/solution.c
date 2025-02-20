#include <stdlib.h>

int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize) {
  int* stack = malloc(heightsSize * sizeof(int));
  int stackSize = 0;

  for (int i = heightsSize - 1; i >= 0; --i) {
    int count = 0;
    while (stackSize > 0 && stack[stackSize - 1] <= heights[i]) {
      ++count;
      --stackSize;
    }
    if (stackSize > 0) ++count;
    stack[stackSize++] = heights[i];
    heights[i] = count;
  }

  free(stack);

  *returnSize = heightsSize;
  return heights;
}
