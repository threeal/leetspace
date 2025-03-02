int numOfSubarrays(int* arr, int arrSize) {
  int count = 0, even = 0, first = 0, second = 0;
  for (int i = 0; i < arrSize; ++i) {
    if (arr[i] % 2 == 0) {
      ++even;
    } else {
      first += even + 1;
      first = first ^ second;
      second = first ^ second;
      first = first ^ second;
      even = 0;
    }
    count = (count + second) % 1000000007;
  }
  return count;
}
