long long smallestNumber(long long num) {
  char freqs[10] = {0};
  if (num >= 0) {
    while (num > 0) {
      ++freqs[num % 10];
      num /= 10;
    }

    int i = 1;
    while (i <= 9 && freqs[i] == 0) ++i;

    if (i <= 9) {
      --freqs[i];
      num = num * 10 + i;

      for (int j = freqs[0]; j > 0; --j) num = num * 10;
      while (i <= 9) {
        for (int j = freqs[i]; j > 0; --j) num = num * 10 + i;
        ++i;
      }
    }

    return num;
  } else {
    num = -num;

    while (num > 0) {
      ++freqs[num % 10];
      num /= 10;
    }

    for (int i = 9; i >= 0; --i) {
      for (int j = freqs[i]; j > 0; --j) num = num * 10 + i;
    }

    return -num;
  }
}
