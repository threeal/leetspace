#include <limits.h>
#include <stdlib.h>

static int search(int* cookies, int cookiesSize, int k, int i, int* children);

int distributeCookies(int* cookies, int cookiesSize, int k) {
  int* children = malloc(k * sizeof(int));
  for (int i = 0; i < k; ++i) children[i] = 0;

  const int res = search(cookies, cookiesSize, k, 0, children);
  free(children);
  return res;
}

static int search(int* cookies, int cookiesSize, int k, int i, int* children) {
  if (i == cookiesSize) {
    int maxChild = 0;
    for (int j = 0; j < k; ++j) {
      if (children[j] > maxChild) maxChild = children[j];
    }
    return maxChild;
  }

  int minMaxChild = INT_MAX;
  for (int j = 0; j < k; ++j) {
    children[j] += cookies[i];
    const int maxChild = search(cookies, cookiesSize, k, i + 1, children);
    if (maxChild < minMaxChild) minMaxChild = maxChild;
    children[j] -= cookies[i];
  }

  return minMaxChild;
}
