int countDigits(int num) {
  int count = 0;
  for (int exp = 1; exp <= num; exp *= 10) {
    if (num % (num / exp % 10) == 0) ++count;
  }
  return count;
}
