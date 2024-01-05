void quickSortByX(int** low, int** high);

int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize) {
  (void)pointsColSize;

  // Sort the x coordinates.
  quickSortByX(points, points + pointsSize - 1);

  // Find the maximum difference between two different x coordinates.
  int prev_x = points[0][0];
  int max_width = 0;
  for (int i = 1; i < pointsSize; ++i) {
    if (points[i][0] == prev_x) continue;
    if (points[i][0] - prev_x > max_width)
      max_width = points[i][0] - prev_x;
    prev_x = points[i][0];
  }

  return max_width;
}

// This function implements quick sort to sort the given range of arrays.
// See: https://www.geeksforgeeks.org/quick-sort/
void quickSortByX(int** low, int** high) {
  if (low >= high) return;

  int** i = low - 1;

  for (int** j = low; j < high; ++j) {
    if (**j >= **high) continue;
    ++i;
    int* temp = *i;
    *i = *j;
    *j = temp;
  }

  ++i;
  int* temp = *i;
  *i = *high;
  *high = temp;

  quickSortByX(low, i - 1);
  quickSortByX(i + 1, high);
}
