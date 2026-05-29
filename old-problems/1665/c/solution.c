#include <stdlib.h>

int compare(const void* a, const void* b) {
  int* aa = *(int**)a;
  int* bb = *(int**)b;
  return (bb[1] - bb[0]) - (aa[1] - aa[0]);
}

int minimumEffort(int** tasks, int tasksSize, int* tasksColSize) {
  (void)tasksColSize;
  qsort(tasks, tasksSize, sizeof(int*), compare);

  int energy = 0, effort = 0;
  for (int i = 0; i < tasksSize; ++i) {
    if (energy < tasks[i][1]) {
      effort += tasks[i][1] - energy;
      energy = tasks[i][1];
    }
    energy -= tasks[i][0];
  }

  return effort;
}
