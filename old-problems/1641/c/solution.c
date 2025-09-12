int countVowelStrings(int n) {
  int e = 1, i = 1, o = 1, u = 1;
  while (e < n) {
    u += 1 + e + i + o;
    o += 1 + e + i;
    i += 1 + e;
    ++e;
  }
  return 1 + e + i + o + u;
}
