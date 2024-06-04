int countTriplets(int* arr, int arrSize) {
  int count = 0;
  for (int k = arrSize - 1; k > 0; --k) {
    int sum = arr[k];
    for (int i = k - 1; i >= 0; --i) {
      sum ^= arr[i];
      if (sum == 0) count += k - i;
    }
  }
  return count;
}
