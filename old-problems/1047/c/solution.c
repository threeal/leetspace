char* removeDuplicates(char* s) {
  int out = 1;
  int i = 1;
  while (s[i] != 0) {
    while (out > 0 && s[i] != 0 && s[out - 1] == s[i]) {
      --out;
      ++i;
    }
    if (s[i] != 0) {
      s[out] = s[i];
      ++out;
      ++i;
    }
  }

  s[out] = 0;
  return s;
}
