#include <stdlib.h>
#include <string.h>

int numOfPairs(char** nums, int numsSize, char* target) {
  const int targetLen = strlen(target);

  int* numsLen = malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; ++i) numsLen[i] = strlen(nums[i]);

  int count = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (numsLen[i] >= targetLen) continue;

    int ii = 0;
    while (ii < numsLen[i] && nums[i][ii] == target[ii]) ++ii;

    if (ii < numsLen[i]) continue;

    for (int j = 0; j < numsSize; ++j) {
      if (i == j || ii + numsLen[j] != targetLen) continue;

      int jj = 0;
      while (jj < numsLen[j] && nums[j][jj] == target[ii + jj]) ++jj;

      if (jj == numsLen[j]) ++count;
    }
  }

  free(numsLen);
  return count;
}
