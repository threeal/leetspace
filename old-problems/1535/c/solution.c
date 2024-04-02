int getWinner(int* arr, int arrSize, int k) {
  int win = 0;
  int ref = 0;

  for (int i = 1; i < arrSize; ++i) {
    if (win >= k) break;
    if (arr[i] > arr[ref]) {
      win = 1;
      ref = i;
    } else {
      ++win;
    }
  }

  return arr[ref];
}
