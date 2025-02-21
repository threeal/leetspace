#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
  return strcmp(*(char**)a, *(char**)b);
}

char* findDifferentBinaryString(char** nums, int numsSize) {
  qsort(nums, numsSize, sizeof(char*), compare);

  char* res = malloc((numsSize + 1) * sizeof(char));
  memset(res, '0', numsSize * sizeof(char));
  res[numsSize] = '\0';

  for (int i = 0; i < numsSize; ++i) {
    if (strcmp(nums[i], res) != 0) break;
    int j = numsSize - 1;
    res[j] += '\1';
    while (res[j] == '2') {
      res[j] = '0';
      --j;
      res[j] += '\1';
    }
  }

  return res;
}
