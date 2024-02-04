#include <stdlib.h>

void quickSort(int* low, int* high);

int** divideArray(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes) {
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i - 1] > nums[i]) {
      quickSort(nums, nums + numsSize - 1);
      break;
    }
  }

  for (int i = 2; i < numsSize; i += 3) {
    if (nums[i] - nums[i - 2] > k) {
      *returnSize = 0;
      return NULL;
    }
  }

  *returnSize = numsSize / 3;

  int** returnData = malloc(*returnSize * sizeof(int*));
  *returnColumnSizes = malloc(*returnSize * sizeof(int));
  for (int i = 0; i < *returnSize; ++i) {
    returnData[i] = malloc(3 * sizeof(int));
    (*returnColumnSizes)[i] = 3;
  }

  for (int i = 0; i < *returnSize; ++i) {
    for (int j = 0; j < 3; ++j) {
      returnData[i][j] = nums[i * 3 + j];
    }
  }

  return returnData;
}

// This function implements quick sort to sort the given range of arrays.
// See: https://www.geeksforgeeks.org/quick-sort/
void quickSort(int* low, int* high) {
  if (low >= high) return;

  int* i = low - 1;

  for (int* j = low; j < high; ++j) {
    if (*j >= *high) continue;
    ++i;
    const int temp = *i;
    *i = *j;
    *j = temp;
  }

  ++i;
  const int temp = *i;
  *i = *high;
  *high = temp;

  quickSort(low, i - 1);
  quickSort(i + 1, high);
}
