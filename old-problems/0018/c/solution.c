#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int** fourSum(
    int* nums, int numsSize, int target,
    int* returnSize, int** returnColumnSizes) {
  qsort(nums, numsSize, sizeof(int), compare);

  int outputMaxSize = numsSize;
  int outputIdx = 0;
  int** output = malloc(outputMaxSize * sizeof(int*));

  int d = numsSize - 1;
  while (d >= 3) {
    int c = d - 1;
    while (c >= 2) {
      const long long targetSum = (long long)target - nums[c] - nums[d];

      int a = 0;
      int b = c - 1;
      while (a < b) {
        const long long sum = (long long)nums[a] + nums[b];
        if (sum == targetSum) {
          if (outputIdx >= outputMaxSize) {
            outputMaxSize *= 2;
            output = realloc(output, outputMaxSize * sizeof(int*));
          }
          output[outputIdx] = malloc(4 * sizeof(int));
          output[outputIdx][0] = nums[a];
          output[outputIdx][1] = nums[b];
          output[outputIdx][2] = nums[c];
          output[outputIdx][3] = nums[d];
          ++outputIdx;
        }

        if (sum < targetSum) {
          ++a;
          while (a < b && nums[a] == nums[a - 1]) ++a;
        } else {
          --b;
          while (a < b && nums[b] == nums[b + 1]) --b;
        }
      }

      --c;
      while (c >= 2 && nums[c] == nums[c + 1]) --c;
    }
    --d;
    while (d >= 3 && nums[d] == nums[d + 1]) --d;
  }

  *returnSize = outputIdx;
  *returnColumnSizes = malloc(*returnSize * sizeof(int));
  for (int i = *returnSize - 1; i >= 0; --i) {
    (*returnColumnSizes)[i] = 4;
  }

  return output;
}
