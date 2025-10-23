#include <limits.h>

int earliestTime(int** tasks, int tasksSize, int* tasksColSize) {
  (void)tasksColSize;
  int earliest = INT_MAX;
  for (int i = 0; i < tasksSize; ++i) {
    if (tasks[i][0] + tasks[i][1] < earliest) {
      earliest = tasks[i][0] + tasks[i][1];
    }
  }
  return earliest;
}
