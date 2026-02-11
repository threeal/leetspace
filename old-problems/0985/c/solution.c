#include <stdlib.h>

int* sumEvenAfterQueries(
    int* nums, int numsSize,
    int** queries, int queriesSize, int* queriesColSize,
    int* returnSize) {
  (void)queriesColSize;

  int sum = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] % 2 == 0) sum += nums[i];
  }

  int* output = malloc(queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; ++i) {
    if (nums[queries[i][1]] % 2 == 0) sum -= nums[queries[i][1]];
    nums[queries[i][1]] += queries[i][0];
    if (nums[queries[i][1]] % 2 == 0) sum += nums[queries[i][1]];
    output[i] = sum;
  }

  *returnSize = queriesSize;
  return output;
}
