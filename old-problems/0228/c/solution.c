#include <stdio.h>
#include <stdlib.h>

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
  if (numsSize == 0) {
    *returnSize = 0;
    return NULL;
  }

  char** output = malloc(numsSize * sizeof(char*));
  char** outputIt = output;

  int begin = nums[0];
  int end = nums[0];
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] == end + 1) {
      ++end;
    } else {
      if (begin == end) {
        *outputIt = malloc(12 * sizeof(char));
        sprintf(*outputIt, "%d", begin);
      } else {
        *outputIt = malloc(25 * sizeof(char));
        sprintf(*outputIt, "%d->%d", begin, end);
      }
      ++outputIt;
      begin = nums[i];
      end = nums[i];
    }
  }

  if (begin == end) {
    *outputIt = malloc(12 * sizeof(char));
    sprintf(*outputIt, "%d", begin);
  } else {
    *outputIt = malloc(25 * sizeof(char));
    sprintf(*outputIt, "%d->%d", begin, end);
  }

  *returnSize = outputIt - output + 1;
  return output;
}
