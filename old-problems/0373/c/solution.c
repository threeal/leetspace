#include <stdbool.h>
#include <stdlib.h>

struct pair_t {
  int val;
  int i1;
  int i2;
};

static bool compare(struct pair_t* a, struct pair_t* b) {
  return a->val != b->val ? a->val < b->val : a->i1 < b->i1;
}

static void pairs_heap_push(
    struct pair_t* heap, int* size, struct pair_t* pair) {
  int i = (*size)++;
  heap[i] = *pair;

  while (i > 0) {
    int parent = (i - 1) / 2;
    if (!compare(&heap[i], &heap[parent])) break;

    const struct pair_t temp = heap[parent];
    heap[parent] = heap[i];
    heap[i] = temp;

    i = parent;
  }
}

static void pairs_heap_pop(struct pair_t* heap, int* size) {
  heap[0] = heap[--(*size)];

  int i = 0;
  while (1) {
    int smallest = i;

    const int left = 2 * i + 1;
    if (left < *size && compare(&heap[left], &heap[smallest])) {
      smallest = left;
    }

    const int right = 2 * i + 2;
    if (right < *size && compare(&heap[right], &heap[smallest])) {
      smallest = right;
    }

    if (smallest == i) break;

    const struct pair_t temp = heap[smallest];
    heap[smallest] = heap[i];
    heap[i] = temp;

    i = smallest;
  }
}

int** kSmallestPairs(
    int* nums1, int nums1Size, int* nums2, int nums2Size, int k,
    int* returnSize, int** returnColumnSizes) {
  struct pair_t* pairs_heap = malloc(nums1Size * sizeof(struct pair_t));
  int pairs_size = 0;

  struct pair_t pair;
  for (int i = 0; i < nums1Size; ++i) {
    pair.val = nums1[i] + nums2[0];
    pair.i1 = i;
    pair.i2 = 0;
    pairs_heap_push(pairs_heap, &pairs_size, &pair);
  }

  *returnSize = k;
  int** output = malloc(k * sizeof(int*));
  *returnColumnSizes = malloc(k * sizeof(int));

  output[0] = malloc(k * 2 * sizeof(int));
  (*returnColumnSizes)[0] = 2;

  for (int i = 1; i < k; ++i) {
    output[i] = output[i - 1] + 2;
    (*returnColumnSizes)[i] = 2;
  }

  for (int i = 0; i < k; ++i) {
    const int i1 = pairs_heap[0].i1;
    const int i2 = pairs_heap[0].i2;
    pairs_heap_pop(pairs_heap, &pairs_size);

    output[i][0] = nums1[i1];
    output[i][1] = nums2[i2];

    if (i2 + 1 < nums2Size) {
      pair.val = nums1[i1] + nums2[i2 + 1];
      pair.i1 = i1;
      pair.i2 = i2 + 1;
      pairs_heap_push(pairs_heap, &pairs_size, &pair);
    }
  }

  return output;
}
