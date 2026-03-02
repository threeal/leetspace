#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int maximizeSquareHoleArea(
    int n, int m, int* hBars, int hBarsSize, int* vBars, int vBarsSize) {
  (void)n;
  (void)m;

  qsort(hBars, hBarsSize, sizeof(int), compare);
  qsort(vBars, vBarsSize, sizeof(int), compare);

  int hMaxCount = 1, hCount = 1;
  for (int i = 1; i < hBarsSize; ++i) {
    if (hBars[i] == hBars[i - 1] + 1) {
      if (++hCount > hMaxCount) hMaxCount = hCount;
    } else {
      hCount = 1;
    }
  }

  int vMaxCount = 1, vCount = 1;
  for (int i = 1; i < vBarsSize; ++i) {
    if (vBars[i] == vBars[i - 1] + 1) {
      if (++vCount > vMaxCount) vMaxCount = vCount;
    } else {
      vCount = 1;
    }
  }

  int maxCount = 1 + (hMaxCount <= vMaxCount ? hMaxCount : vMaxCount);
  return maxCount * maxCount;
}
