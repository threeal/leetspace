int getLeastFrequentDigit(int n) {
  int freqs[10] = {0};
  while (n != 0) {
    ++freqs[n % 10];
    n /= 10;
  }

  int least = 0;
  while (freqs[least] == 0) ++least;

  for (int digit = least + 1; digit < 10; ++digit) {
    if (freqs[digit] != 0 && freqs[digit] < freqs[least]) least = digit;
  }

  return least;
}
