#include <stdbool.h>
#include <stdlib.h>

static int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

static int findGcd(int a, int b) {
  int tmp;
  while (b) {
    tmp = a % b;
    a = b;
    b = tmp;
  }
  return a < 0 ? -a : a;
}

bool hasGroupsSizeX(int* deck, int deckSize) {
  qsort(deck, deckSize, sizeof(int), compare);

  int n = 1;
  while (n < deckSize && deck[n - 1] == deck[n]) ++n;
  if (n == 1) return false;

  int r = n;
  while (r < deckSize) {
    const int l = r;
    ++r;

    while (r < deckSize && deck[r - 1] == deck[r]) ++r;

    n = findGcd(n, r - l);
    if (n == 1) return false;
  }

  return true;
}
