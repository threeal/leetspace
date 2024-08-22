#include <stdlib.h>

int* fairCandySwap(
    int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize,
    int* returnSize) {
  int* output = malloc(2 * sizeof(int));

  output[0] = aliceSizes[aliceSizesSize - 1];
  output[1] = bobSizes[bobSizesSize - 1];

  *returnSize = 2;
  return output;
}
