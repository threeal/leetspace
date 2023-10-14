int lengthOfLastWord(char* s) {
  int a = 0;
  int b = a;

  int res = 0;
  while (s[b] != 0) {
    if (s[b] == ' ') {
      if (b - a > res) {
        res = b - a;
      }
      a = b + 1;
    }
    ++b;
  }

  if (b - a > res) {
    res = b - a;
  }

  return res;
}
