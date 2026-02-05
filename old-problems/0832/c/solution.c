#include <limits.h>
#include <stdlib.h>

struct project_t {
  int difficulty;
  int profit;
};

int compProject(const void* a, const void* b) {
  return ((struct project_t*)a)->difficulty -
      ((struct project_t*)b)->difficulty;
}

int compIntReversed(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

int maxProfitAssignment(
    int* difficulty, int difficultySize,
    int* profit, int profitSize,
    int* worker, int workerSize) {
  (void)profitSize;

  struct project_t* projects =
      malloc((difficultySize + 1) * sizeof(struct project_t));

  for (int i = difficultySize - 1; i >= 0; --i) {
    projects[i].difficulty = difficulty[i];
    projects[i].profit = profit[i];
  }
  projects[difficultySize].difficulty = INT_MAX;

  qsort(projects, difficultySize + 1, sizeof(struct project_t), compProject);
  qsort(worker, workerSize, sizeof(int), compIntReversed);

  int profits = 0;
  int maxProfit = 0;
  struct project_t* projectIt = projects;
  for (int i = workerSize - 1; i >= 0; --i) {
    while (projectIt->difficulty <= worker[i]) {
      if (projectIt->profit > maxProfit) maxProfit = projectIt->profit;
      ++projectIt;
    }
    profits += maxProfit;
  }

  free(projects);

  return profits;
}
