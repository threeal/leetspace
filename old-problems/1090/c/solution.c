#include <stdlib.h>

int* globalValues = NULL;
int* globalLabels = NULL;

int compareIndex(const void* a, const void* b) {
  return globalLabels[*(int*)a] == globalLabels[*(int*)b]
      ? globalValues[*(int*)a] - globalValues[*(int*)b]
      : globalLabels[*(int*)a] - globalLabels[*(int*)b];
}

int compareInt(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int largestValsFromLabels(
    int* values, int valuesSize, int* labels, int labelsSize,
    int numWanted, int useLimit) {
  (void)labelsSize;

  int* indexes = malloc(valuesSize * sizeof(int));
  for (int i = valuesSize - 1; i >= 0; --i) {
    indexes[i] = i;
  }

  globalValues = values;
  globalLabels = labels;
  qsort(indexes, valuesSize, sizeof(int), compareIndex);

  int label = labels[indexes[valuesSize - 1]];
  int count = useLimit - 1;
  for (int i = valuesSize - 2; i >= 0; --i) {
    if (labels[indexes[i]] == label) {
      if (count > 0) {
        --count;
      } else {
        values[indexes[i]] = -1;
      }
    } else {
      label = labels[indexes[i]];
      count = useLimit - 1;
    }
  }

  qsort(values, valuesSize, sizeof(int), compareInt);

  int sum = 0;
  for (int i = valuesSize - 1; numWanted > 0; --i, --numWanted) {
    if (values[i] < 0) break;
    sum += values[i];
  }

  free(indexes);

  return sum;
}
