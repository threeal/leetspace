#include <stdbool.h>

bool searchMatrix(
    int** matrix, int matrixSize, int* matrixColSize, int target) {
  int vLow = 0, vHigh = matrixSize - 1;
  while (vLow < vHigh) {
    int mid = vLow + (vHigh - vLow) / 2;
    if (matrix[mid][matrixColSize[mid] - 1] < target) {
      vLow = mid + 1;
    } else {
      vHigh = mid;
    }
  }

  if (matrix[vLow][matrixColSize[vLow] - 1] < target) return false;

  int hLow = 0, hHigh = matrixColSize[vLow] - 1;
  while (hLow < hHigh) {
    int mid = hLow + (hHigh - hLow) / 2;
    if (matrix[vLow][mid] < target) {
      hLow = mid + 1;
    } else {
      hHigh = mid;
    }
  }

  return matrix[vLow][hLow] == target;
}
