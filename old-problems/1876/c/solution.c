int countGoodSubstrings(char* s) {
  if (s[1] == 0 || s[2] == 0) return 0;
  int count = 0;
  while (s[2] != 0) {
    if (s[0] != s[1] && s[0] != s[2] && s[1] != s[2]) ++count;
    ++s;
  }
  return count;
}
