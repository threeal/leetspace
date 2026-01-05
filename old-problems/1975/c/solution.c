#include <stdbool.h>

long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
  long long sum = 0;
  int negCount = 0, minVal = 100000;
  bool hasZero = false;
  for (int i = 0; i < matrixSize; ++i) {
    for (int j = 0; j < matrixColSize[i]; ++j) {
      const int val = matrix[i][j];
      if (val == 0) {
        hasZero = true;
      } else if (val < 0) {
        ++negCount;
        sum += -val;
        if (-val < minVal) minVal = -val;
      } else {
        sum += val;
        if (val < minVal) minVal = val;
      }
    }
  }
  if (!hasZero && negCount % 2 == 1) sum -= 2 * minVal;
  return sum;
}
