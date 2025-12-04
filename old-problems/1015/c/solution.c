#include <stdbool.h>
#include <stdlib.h>

int smallestRepunitDivByK(int k) {
  int val = 1 % k, len = 1;

  bool* visited = malloc(k * sizeof(bool));
  for (int i = 0; i < k; ++i) visited[i] = false;
  visited[val] = true;

  while (val != 0) {
    val = (val * 10 + 1) % k;
    if (visited[val]) return -1;
    visited[val] = true;
    ++len;
  }

  return len;
}
