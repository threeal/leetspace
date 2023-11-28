// We will do a brute force search here to find the maximum area of the submatrix.
// But before that, we need to adjust each element of the matrix so it contains
// 1 + the number of the above elements whose value is 1.
//
// Given the example input:
//
//   [ 0 0 1 ]
//   [ 1 1 1 ]
//   [ 1 0 1 ]
//
// We will adjust it to be:
//
//   [ 0 0 1 ]
//   [ 1 1 2 ]
//   [ 2 0 3 ]
//
// And then we can just iterate each row to find the maximum area.
// To calculate each row, we can sort the row first from highest to lowest
// and then calculate the area by multiplying the element value with the element index + 1.
//
// Given the second row of the adjusted example matrix:
//
//   [ 1 2 2 ]
//
// We can sort it to be:
//
//   [ 2 2 1 ]
//
// And we can just choose the largest area as follows:
//
//   2 * 1 = 2
//   2 * 2 = 4 (largest)
//   1 * 3 = 3

void reversedQuickSort(int* low, int* high);

int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize) {
  // Adjust each element of the matrix so it contains
  // 1 + the number of the above elements whose value is 1.
  for (int y = 1; y < matrixSize; ++y) {
    for (int x = 0; x < matrixColSize[y]; ++x) {
      if (matrix[y][x] == 0) continue;
      matrix[y][x] = matrix[y - 1][x] + 1;
    }
  }

  // Do brute force search here to calculate the maximum area.
  int maxArea = 0;
  for (int y = 0; y < matrixSize; ++y) {
    // Sort values in the row from highest to lowest (don't sort if already sorted).
    for (int x = 1; x < matrixColSize[y]; ++x) {
      if (matrix[y][x - 1] < matrix[y][x]) {
        reversedQuickSort(matrix[y], matrix[y] + matrixColSize[y] - 1);
        break;
      }
    }

    // Find the largest area from values in the row.
    for (int x = 0; x < matrixColSize[y]; ++x) {
      if (matrix[y][x] == 0) break;
      if ((x + 1) * matrix[y][x] > maxArea)
        maxArea = (x + 1) * matrix[y][x];
    }
  }

  return maxArea;
}

// This function implements quick sort to sort the given range of arrays.
// See: https://www.geeksforgeeks.org/quick-sort/
void reversedQuickSort(int* low, int* high) {
  if (low >= high) return;

  int* i = low - 1;

  for (int* j = low; j < high; ++j) {
    if (*j <= *high) continue;
    ++i;
    const int temp = *i;
    *i = *j;
    *j = temp;
  }

  ++i;
  const int temp = *i;
  *i = *high;
  *high = temp;

  reversedQuickSort(low, i - 1);
  reversedQuickSort(i + 1, high);
}
