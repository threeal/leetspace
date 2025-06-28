#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
  return (*(int**)a)[0] == (*(int**)b)[0]
      ? (*(int**)a)[1] - (*(int**)b)[1]
      : (*(int**)a)[0] - (*(int**)b)[0];
}

int* findingUsersActiveMinutes(
    int** logs, int logsSize, int* logsColSize, int k, int* returnSize) {
  (void)logsColSize;

  qsort(logs, logsSize, sizeof(int*), compare);

  int* output = malloc(k * sizeof(int));
  memset(output, 0, k * sizeof(int));

  int i = 0;
  while (i < logsSize) {
    int uam = 1;

    ++i;
    while (i < logsSize && logs[i][0] == logs[i - 1][0]) {
      if (logs[i][1] != logs[i - 1][1]) ++uam;
      ++i;
    }

    ++output[uam - 1];
  }

  *returnSize = k;
  return output;
}
