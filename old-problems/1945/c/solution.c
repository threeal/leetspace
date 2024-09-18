int getLucky(char* s, int k) {
  int num = 0;
  while (*s != 0) {
    if (*s > 115) {
      num += *s - 114;
    } else if (*s > 105) {
      num += *s - 105;
    } else {
      num += *s - 96;
    }
    ++s;
  }

  while (--k > 0) {
    int temp = 0;
    while (num > 0) {
      temp += num % 10;
      num /= 10;
    }
    num = temp;
  }

  return num;
}
