int countNumbersWithUniqueDigits(int n) {
  static const int counts[] = {
      1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851};
  return counts[n];
}
