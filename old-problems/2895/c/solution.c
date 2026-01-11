#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int compareGreater(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

int minProcessingTime(
    int* processorTime, int processorTimeSize, int* tasks, int tasksSize) {
  qsort(processorTime, processorTimeSize, sizeof(int), compare);
  qsort(tasks, tasksSize, sizeof(int), compareGreater);

  int maxTime = 0;
  for (int i = 0; i < processorTimeSize; ++i) {
    for (int j = 0; j < 4; ++j) {
      const int time = processorTime[i] + tasks[i * 4 + j];
      if (time > maxTime) maxTime = time;
    }
  }

  return maxTime;
}
