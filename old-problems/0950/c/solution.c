#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

static int* reorder(int* deck, int deckSize, int l, int* returnSize);

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {
  qsort(deck, deckSize, sizeof(int), compare);
  return reorder(deck, deckSize, 0, returnSize);
}

static int* reorder(int* deck, int deckSize, int l, int* returnSize) {
  if (l == deckSize - 1) {
    int* output = malloc(sizeof(int));
    output[0] = deck[deckSize - 1];
    return output;
  }

  const int n = deckSize - l;
  const int mid = n / 2 + n % 2;

  int* output = malloc(n * sizeof(int));
  for (int i = 0; i < mid; ++i) {
    output[i * 2] = deck[l + i];
  }

  int rDeckSize;
  int* rDeck = reorder(deck, deckSize, l + mid, &rDeckSize);

  if (rDeckSize == mid) {
    for (int i = 0; i < rDeckSize; ++i) {
      output[i * 2 + 1] = rDeck[i];
    }
  } else {
    output[1] = rDeck[rDeckSize - 1];
    for (int i = 1; i < rDeckSize; ++i) {
      output[i * 2 + 1] = rDeck[i - 1];
    }
  }

  // free(rDeck);

  *returnSize = n;
  return output;
}
