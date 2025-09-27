#include <stdbool.h>

int numberOfPairs(int** points, int pointsSize, int* pointsColSize) {
  (void)pointsColSize;
  int count = 0;
  for (int i = 0; i < pointsSize; ++i) {
    for (int j = 0; j < pointsSize; ++j) {
      if (i != j &&
          points[i][0] <= points[j][0] &&
          points[i][1] >= points[j][1]) {
        bool valid = true;
        for (int k = 0; k < pointsSize; ++k) {
          if (k != i && k != j &&
              points[k][0] >= points[i][0] &&
              points[k][0] <= points[j][0] &&
              points[k][1] <= points[i][1] &&
              points[k][1] >= points[j][1]) {
            valid = false;
            break;
          }
        }
        if (valid) ++count;
      }
    }
  }
  return count;
}
