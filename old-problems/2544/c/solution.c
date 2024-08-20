int alternateDigitSum(int n) {
  int sum = 0;
  while (n > 0) {
    sum -= n % 10;
    n /= 10;
    if (n == 0) return -sum;

    sum += n % 10;
    n /= 10;
  }
  return sum;
}
