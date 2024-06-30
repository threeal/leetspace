#include <stdlib.h>

struct project_t {
  int profit;
  int capital;
};

int compProject(const void* a, const void* b) {
  return ((struct project_t*)a)->capital != ((struct project_t*)b)->capital
      ? ((struct project_t*)a)->capital - ((struct project_t*)b)->capital
      : ((struct project_t*)a)->profit - ((struct project_t*)b)->profit;
}

int compInt(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int findMaximizedCapital(
    int k, int w,
    int* profits, int profitsSize,
    int* capital, int capitalSize) {
  (void)capitalSize;

  struct project_t* projects = malloc(profitsSize * sizeof(struct project_t));
  for (int i = profitsSize - 1; i >= 0; --i) {
    projects[i].profit = profits[i];
    projects[i].capital = capital[i];
  }

  qsort(projects, profitsSize, sizeof(struct project_t), compProject);
  struct project_t* projectsIt = projects;
  struct project_t* projectsEnd = projects + profitsSize;

  int* maxProfits = malloc(profitsSize * sizeof(int));
  int* maxProfitsIt = maxProfits;

  while (--k >= 0) {
    if (projectsIt != projectsEnd && projectsIt->capital <= w) {
      do {
        *maxProfitsIt = projectsIt->profit;
        ++maxProfitsIt;
        ++projectsIt;
      } while (projectsIt != projectsEnd && projectsIt->capital <= w);

      qsort(maxProfits, maxProfitsIt - maxProfits, sizeof(int), compInt);
    }

    if (maxProfitsIt == maxProfits) return w;

    --maxProfitsIt;
    w += *maxProfitsIt;
  }

  free(maxProfits);
  free(projects);

  return w;
}
