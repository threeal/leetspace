int countEven(int num) {
  int count = 0;
  for (int i = 1; i <= num; ++i) {
    int ii = i, sum = 0;
    while (ii != 0) {
      sum += ii % 10;
      ii /= 10;
    }
    if (sum % 2 == 0) ++count;
  }
  return count;
}
