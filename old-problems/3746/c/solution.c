int minLengthAfterRemovals(char* s) {
  int a = 0, n = 0;
  while (s[n] != 0) {
    if (s[n] == 'a') ++a;
    ++n;
  }
  a *= 2;
  return a >= n ? a - n : n - a;
}
