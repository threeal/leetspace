#include <stdlib.h>

static int calc_gcd(int a, int b) {
  return b == 0 ? a : calc_gcd(b, a % b);
}

static int compare(const void* a, const void* b) {
  int* aa = *(int**)a;
  int* bb = *(int**)b;
  return aa[0] != bb[0] ? aa[0] - bb[0] : aa[1] - bb[1];
}

long long interchangeableRectangles(
    int** rectangles, int rectanglesSize, int* rectanglesColSize) {
  (void)rectanglesColSize;

  for (int i = 0; i < rectanglesSize; ++i) {
    const int gcd = calc_gcd(rectangles[i][0], rectangles[i][1]);
    rectangles[i][0] /= gcd;
    rectangles[i][1] /= gcd;
  }

  qsort(rectangles, rectanglesSize, sizeof(int*), compare);

  long long totalCount = 0, count = 0;
  for (int i = 1; i < rectanglesSize; ++i) {
    if (rectangles[i][0] == rectangles[i - 1][0] &&
        rectangles[i][1] == rectangles[i - 1][1]) {
      totalCount += ++count;
    } else {
      count = 0;
    }
  }

  return totalCount;
}
