#include <stdlib.h>

int compare(const void* a, const void* b) {
  int* aa = *(int**)a;
  int* bb = *(int**)b;
  return aa[0] == bb[0] ? aa[1] - bb[1] : aa[0] - bb[0];
}

void heap_push(int* heap, int* size, int val) {
  int i = (*size)++;
  heap[i] = val;

  while (i > 0) {
    int parent = (i - 1) / 2;
    if (heap[parent] >= heap[i]) break;

    const int temp = heap[parent];
    heap[parent] = heap[i];
    heap[i] = temp;

    i = parent;
  }
}

void heap_pop(int* heap, int* size) {
  heap[0] = heap[--(*size)];

  int i = 0;
  while (1) {
    int smallest = i;

    const int left = 2 * i + 1;
    if (left < *size && heap[left] > heap[smallest]) {
      smallest = left;
    }

    const int right = 2 * i + 2;
    if (right < *size && heap[right] > heap[smallest]) {
      smallest = right;
    }

    if (smallest == i) break;

    const int temp = heap[smallest];
    heap[smallest] = heap[i];
    heap[i] = temp;

    i = smallest;
  }
}

int maxRemoval(
    int* nums, int numsSize,
    int** queries, int queriesSize, int* queriesColSize) {
  (void)queriesColSize;

  qsort(queries, queriesSize, sizeof(int*), compare);

  for (int i = numsSize - 1; i > 0; --i) {
    nums[i] -= nums[i - 1];
  }

  int num = 0;

  int* ends = malloc(queriesSize * sizeof(int));
  int endsSize = 0;

  for (int i = 0, j = 0; i < numsSize; ++i) {
    num += nums[i];
    while (j < queriesSize && queries[j][0] == i) {
      heap_push(ends, &endsSize, queries[j][1]);
      ++j;
    }

    while (num > 0 && endsSize != 0 && i <= ends[0]) {
      --num;
      if (ends[0] + 1 < numsSize) {
        ++nums[ends[0] + 1];
      }
      heap_pop(ends, &endsSize);
    }

    if (num > 0) return -1;
  }

  free(ends);
  return endsSize;
}
