#include <stdlib.h>
#include <string.h>

int compareLogs(const void* a, const void* b) {
  return (*(int**)a)[1] - (*(int**)b)[1];
}

int* gQueries;
int compareQueries(const void* a, const void* b) {
  return gQueries[*(int*)a] - gQueries[*(int*)b];
}

int* countServers(
    int n, int** logs, int logsSize, int* logsColSize, int x,
    int* queries, int queriesSize, int* returnSize) {
  (void)logsColSize;

  qsort(logs, logsSize, sizeof(int*), compareLogs);

  int* queryIdxs = malloc(queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; ++i) queryIdxs[i] = i;

  gQueries = queries;
  qsort(queryIdxs, queriesSize, sizeof(int), compareQueries);

  int currentMissing = n;
  int* currentRequests = malloc(n * sizeof(int));
  memset(currentRequests, 0, n * sizeof(int));
  int** startLog = logs;
  int** endLog = logs;

  int* missings = malloc(queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; ++i) {
    const int end = queries[queryIdxs[i]];
    while (startLog != logs + logsSize && (*startLog)[1] <= end) {
      const int id = (*startLog)[0] - 1;
      if (currentRequests[id] == 0) --currentMissing;
      ++currentRequests[id];
      ++startLog;
    }

    const int start = queries[queryIdxs[i]] - x;
    while (endLog != logs + logsSize && (*endLog)[1] < start) {
      const int id = (*endLog)[0] - 1;
      if (currentRequests[id] == 1) ++currentMissing;
      --currentRequests[id];
      ++endLog;
    }

    missings[queryIdxs[i]] = currentMissing;
  }

  free(currentRequests);
  free(queryIdxs);

  *returnSize = queriesSize;
  return missings;
}
