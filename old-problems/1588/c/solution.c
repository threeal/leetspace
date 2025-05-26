int sumOddLengthSubarrays(int* arr, int arrSize) {
  int sum = 0;
  for (int i = 0; i < arrSize; ++i) {
    sum += ((i + 1) * (arrSize - i) + 1) / 2 * arr[i];
  }
  return sum;
}
