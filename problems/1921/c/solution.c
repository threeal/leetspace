void quickSort(int* low, int* high);

int eliminateMaximum(int* dist, int distSize, int* speed, int speedSize) {
  // Calculate the time required before enemies reach distance zero.
  (void)speedSize;

  for (int i = 0; i < distSize; ++i) {
    dist[i] = dist[i] / speed[i] + (dist[i] % speed[i] > 0 ? 1 : 0);
  }

  // Sort the time required from lowest to highest (don't sort if already sorted).
  for (int i = 1; i < distSize; ++i) {
    if (dist[i - 1] > dist[i]) {
      quickSort(dist, dist + distSize - 1);
      break;
    }
  }

  // Time equals to kills. Iterate through the time required as long as the current time is not greater than the time required.
  int kills = 0;
  for (int i = 0; i < distSize; ++i) {
    if (kills + 1 > dist[i]) break;
    ++kills;
  }

  return kills;
}

// This function implements quick sort to sort the given range of arrays.
// See: https://www.geeksforgeeks.org/quick-sort/
void quickSort(int* low, int* high) {
  if (low >= high) return;

  int* i = low - 1;

  for (int* j = low; j < high; ++j) {
    if (*j >= *high) continue;
    ++i;
    const int temp = *i;
    *i = *j;
    *j = temp;
  }

  ++i;
  const int temp = *i;
  *i = *high;
  *high = temp;

  quickSort(low, i - 1);
  quickSort(i + 1, high);
}
