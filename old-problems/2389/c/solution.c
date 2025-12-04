#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int* gQueries;
int compareQueryIndices(const void* a, const void* b) {
  return gQueries[*(int*)a] - gQueries[*(int*)b];
}

int* answerQueries(
    int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
  int* queryIndices = malloc(queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; ++i) queryIndices[i] = i;

  qsort(nums, numsSize, sizeof(int), compare);

  gQueries = queries;
  qsort(queryIndices, queriesSize, sizeof(int), compareQueryIndices);

  int sum = 0, numsI = 0;
  for (int i = 0; i < queriesSize; ++i) {
    const int index = queryIndices[i];
    while (numsI < numsSize && sum + nums[numsI] <= queries[index]) {
      sum += nums[numsI++];
    }
    queries[index] = numsI;
  }

  *returnSize = queriesSize;
  return queries;
}
