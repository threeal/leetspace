#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int maxTaskAssign(
    int* tasks, int tasksSize, int* workers, int workersSize,
    int pills, int strength) {
  qsort(tasks, tasksSize, sizeof(int), compare);
  qsort(workers, workersSize, sizeof(int), compare);

  int* unassigned = malloc(workersSize * sizeof(int));

  int low = 0;
  int high = tasksSize < workersSize ? tasksSize : workersSize;
  while (low < high) {
    const int mid = high - (high - low) / 2;

    bool isValid = true;
    int freePills = pills;

    int unassignedSize = 0;
    for (int i = 0, j = workersSize; i < mid; ++i) {
      const int task = tasks[mid - i - 1];
      if (unassignedSize > 0 && unassigned[0] >= task) {
        --unassignedSize;
      } else if (j > 0 && workers[j - 1] >= task) {
        --j;
      } else {
        while (j > 0 && workers[j - 1] + strength >= task) {
          unassigned[unassignedSize++] = workers[--j];
        }
        if (unassignedSize == 0 || freePills == 0) {
          isValid = false;
          break;
        }
        --unassignedSize;
        --freePills;
      }
    }

    if (isValid) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }

  free(unassigned);
  return low;
}
