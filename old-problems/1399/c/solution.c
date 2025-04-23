int countLargestGroup(int n) {
  int counts[37] = {0};
  while (n > 0) {
    ++counts[(n / 10000) % 10 + (n / 1000) % 10 + (n / 100) % 10 + (n / 10) % 10 + n % 10];
    --n;
  }

  int max = 0, count = 0;
  for (int i = 0; i < 37; ++i) {
    if (counts[i] >= max) {
      if (counts[i] == max) {
        ++count;
      } else {
        max = counts[i];
        count = 1;
      }
    }
  }

  return count;
}
