#include <stdlib.h>

int* minDifference(
    int* nums, int numsSize,
    int** queries, int queriesSize, int* queriesColSize,
    int* returnSize) {
  (void)nums;
  (void)numsSize;
  (void)queries;
  (void)queriesColSize;

  int* returnData = malloc(queriesSize * sizeof(int));
  *returnSize = queriesSize;
  return returnData;
}
