char* removeKdigits(char* num, int k) {
  int n = 0, i = 0;
  while (num[i] != 0 && k > 0) {
    while (k > 0 && n > 0 && num[n - 1] > num[i]) {
      --n;
      --k;
    }
    if (n == 0 && num[i] == '0') {
      ++i;
    } else {
      num[n++] = num[i++];
    }
  }

  while (k > 0 && n > 0) {
    --n;
    --k;
  };

  while (num[i] != 0) {
    if (n == 0 && num[i] == '0') {
      ++i;
    } else {
      num[n++] = num[i++];
    }
  }

  if (n == 0) return "0";

  num[n] = 0;
  return num;
}
