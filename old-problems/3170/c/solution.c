#include <stdlib.h>
#include <string.h>

struct pair_t {
  char c;
  int i;
};

static void pairs_heap_push(
    struct pair_t* heap, int* size, struct pair_t* pair) {
  int i = (*size)++;
  heap[i] = *pair;

  while (i > 0) {
    int parent = (i - 1) / 2;
    if (heap[parent].c == heap[i].c) {
      if (heap[parent].i >= heap[i].i) break;
    } else {
      if (heap[parent].c <= heap[i].c) break;
    }

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
    if (left < *size) {
      if (heap[left].c == heap[smallest].c) {
        if (heap[left].i > heap[smallest].i) smallest = left;
      } else {
        if (heap[left].c < heap[smallest].c) smallest = left;
      }
    }

    const int right = 2 * i + 2;
    if (right < *size) {
      if (heap[right].c == heap[smallest].c) {
        if (heap[right].i > heap[smallest].i) smallest = right;
      } else {
        if (heap[right].c < heap[smallest].c) smallest = right;
      }
    }

    if (smallest == i) break;

    const struct pair_t temp = heap[smallest];
    heap[smallest] = heap[i];
    heap[i] = temp;

    i = smallest;
  }
}

char* clearStars(char* s) {
  const int sLen = strlen(s);

  struct pair_t* pairs_heap = malloc(sLen * sizeof(struct pair_t));
  int pairs_size = 0;

  struct pair_t pair;
  for (int i = 0; i < sLen; ++i) {
    if (s[i] == '*') {
      s[pairs_heap[0].i] = '*';
      pairs_heap_pop(pairs_heap, &pairs_size);
    } else {
      pair.c = s[i];
      pair.i = i;
      pairs_heap_push(pairs_heap, &pairs_size, &pair);
    }
  }

  int n = 0;
  for (int i = 0; i < sLen; ++i) {
    if (s[i] != '*') s[n++] = s[i];
  }
  s[n] = 0;

  return s;
}
