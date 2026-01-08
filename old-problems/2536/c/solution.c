#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
  return (*(int**)a)[0] - (*(int**)b)[0];
}

void heapPush(int** heap, int* size, int* val) {
  int i = (*size)++;
  heap[i] = val;

  while (i > 0) {
    int parent = (i - 1) / 2;
    if (heap[parent][2] <= heap[i][2]) break;

    int* temp = heap[parent];
    heap[parent] = heap[i];
    heap[i] = temp;

    i = parent;
  }
}

void heapPop(int** heap, int* size) {
  heap[0] = heap[--(*size)];

  int i = 0;
  while (1) {
    int smallest = i;

    const int left = 2 * i + 1;
    if (left < *size && heap[left][2] < heap[smallest][2]) {
      smallest = left;
    }

    const int right = 2 * i + 2;
    if (right < *size && heap[right][2] < heap[smallest][2]) {
      smallest = right;
    }

    if (smallest == i) break;

    int* temp = heap[smallest];
    heap[smallest] = heap[i];
    heap[i] = temp;

    i = smallest;
  }
}

int** rangeAddQueries(
    int n, int** queries, int queriesSize, int* queriesColSize,
    int* returnSize, int** returnColumnSizes) {
  (void)queriesColSize;

  int queriesIdx = 0;
  qsort(queries, queriesSize, sizeof(int*), compare);

  int** endQueries = malloc(queriesSize * sizeof(int*));
  int endQueriesSize = 0;

  int** output = malloc(n * sizeof(int*));
  int* outputColSizes = malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    output[i] = malloc(n * sizeof(int));
    memset(output[i], 0, n * sizeof(int));
    outputColSizes[i] = n;
  }

  int* prefixSum = malloc((n + 1) * sizeof(int));
  memset(prefixSum, 0, (n + 1) * sizeof(int));

  for (int i = 0; i < n; ++i) {
    while (queriesIdx < queriesSize && queries[queriesIdx][0] == i) {
      ++prefixSum[queries[queriesIdx][1]];
      --prefixSum[queries[queriesIdx][3] + 1];
      heapPush(endQueries, &endQueriesSize, queries[queriesIdx]);
      ++queriesIdx;
    }

    for (int j = 0, sum = 0; j < n; ++j) {
      sum += prefixSum[j];
      output[i][j] = sum;
    }

    while (endQueriesSize != 0 && endQueries[0][2] == i) {
      --prefixSum[endQueries[0][1]];
      ++prefixSum[endQueries[0][3] + 1];
      heapPop(endQueries, &endQueriesSize);
    }
  }

  free(endQueries);
  free(prefixSum);

  *returnSize = n;
  *returnColumnSizes = outputColSizes;
  return output;
}
