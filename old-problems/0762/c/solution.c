int countPrimeSetBits(int left, int right) {
  int count = 0;
  for (int num = left; num <= right; ++num) {
    switch (__builtin_popcount(num)) {
      case 2:
      case 3:
      case 5:
      case 7:
      case 11:
      case 13:
      case 17:
      case 19:
        ++count;
    }
  }
  return count;
}
