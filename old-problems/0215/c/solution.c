#include <stdlib.h>

void heapPush(int* heap, int* size, int val) {
  int i = (*size)++;
  heap[i] = val;

  while (i > 0) {
    int parent = (i - 1) / 2;
    if (heap[parent] <= heap[i]) break;

    const int temp = heap[parent];
    heap[parent] = heap[i];
    heap[i] = temp;

    i = parent;
  }
}

void heapPop(int* heap, int* size) {
  heap[0] = heap[--(*size)];

  int i = 0;
  while (1) {
    int smallest = i;

    const int left = 2 * i + 1;
    if (left < *size && heap[left] < heap[smallest]) {
      smallest = left;
    }

    const int right = 2 * i + 2;
    if (right < *size && heap[right] < heap[smallest]) {
      smallest = right;
    }

    if (smallest == i) break;

    const int temp = heap[smallest];
    heap[smallest] = heap[i];
    heap[i] = temp;

    i = smallest;
  }
}

int findKthLargest(int* nums, int numsSize, int k) {
  int* largests = malloc(numsSize * sizeof(int));
  int largestsSize = 0;
  for (int i = 0; i < k; ++i) {
    heapPush(largests, &largestsSize, nums[i]);
  }

  for (int i = k; i < numsSize; ++i) {
    if (nums[i] > largests[0]) {
      heapPop(largests, &largestsSize);
      heapPush(largests, &largestsSize, nums[i]);
    }
  }

  return largests[0];
}
