#include <stdlib.h>
#include <stdbool.h>

bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize) {
  bool* isArithmetics = malloc(sizeof(bool) * lSize);
  *returnSize = lSize;

  (void)nums;
  (void)numsSize;
  (void)l;
  (void)r;
  (void)rSize;

  return isArithmetics;
}
