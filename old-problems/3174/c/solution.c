char* clearDigits(char* s) {
  int n = 0;
  for (int i = 0; s[i] != 0; ++i) {
    if (s[i] >= '0' && s[i] <= '9') {
      --n;
    } else {
      s[n] = s[i];
      ++n;
    }
  }
  s[n] = 0;
  return s;
}
