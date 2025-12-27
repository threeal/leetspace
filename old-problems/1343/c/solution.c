int numOfSubarrays(int* arr, int arrSize, int k, int threshold) {
  threshold *= k;

  int sum = 0;
  for (int i = 0; i < k; ++i) sum += arr[i];

  int count = sum >= threshold ? 1 : 0;
  for (int i = k; i < arrSize; ++i) {
    sum -= arr[i - k];
    sum += arr[i];
    if (sum >= threshold) ++count;
  }

  return count;
}
