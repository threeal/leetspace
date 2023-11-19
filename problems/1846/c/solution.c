void quickSort(int* low, int* high);

int maximumElementAfterDecrementingAndRearranging(int* arr, int arrSize) {
  // Sort the time required from lowest to highest (don't sort if already sorted).
  for (int i = 1; i < arrSize; ++i) {
    if (arr[i - 1] > arr[i]) {
      quickSort(arr, arr + arrSize - 1);
      break;
    }
  }

  int res = 0;
  for (int i = 0; i < arrSize; ++i) {
    res = res + 1 < arr[i] ? res + 1 : arr[i];
  }

  return res;
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
