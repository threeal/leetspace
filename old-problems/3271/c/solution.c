char* stringHash(char* s, int k) {
  int i = 0;
  while (s[i] != 0) {
    char hash = 0;
    for (int j = 0; j < k; ++j) {
      hash = (hash + s[i + j] - 'a') % 26;
    }
    s[i / k] = 'a' + hash;
    i += k;
  }
  s[i / k] = 0;
  return s;
}
