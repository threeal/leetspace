int findLengthOfShortestSubarray(int* arr, int arrSize) {
  int left = 0;
  while (left + 1 < arrSize && arr[left] <= arr[left + 1]) ++left;
  if (left + 1 == arrSize) return 0;

  int right = arrSize - 1;
  while (arr[right - 1] <= arr[right]) --right;

  int removed = arrSize - left - 1;
  if (right < removed) removed = right;

  int l = 0, r = right;
  while (l <= left && r < arrSize) {
    if (arr[l] <= arr[r]) {
      if (r - l - 1 < removed) removed = r - l - 1;
      ++l;
    } else {
      ++r;
    }
  }

  return removed;
}
