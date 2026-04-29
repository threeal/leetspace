int residuePrefixes(char* s) {
  int count = 0, distincts = 0;
  for (int i = 0; s[i] != 0; ++i) {
    distincts |= 1 << (s[i] - 'a');
    if (__builtin_popcount(distincts) == (i + 1) % 3) ++count;
  }
  return count;
}
