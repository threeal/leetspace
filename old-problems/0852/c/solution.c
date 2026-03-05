int peakIndexInMountainArray(int* arr, int arrSize) {
  int low = 0, high = arrSize - 2;
  while (low < high) {
    const int mid = low + (high - low) / 2;
    if (arr[mid] < arr[mid + 1]) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return low;
}
