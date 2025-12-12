int countSubstrings(char* s, char* t) {
  int count = 0;
  for (int i = 0; s[i] != 0; ++i) {
    for (int j = 0; t[j] != 0; ++j) {
      int ii = i, jj = j;
      while (s[ii] != 0 && t[jj] != 0 && s[ii] == t[jj]) ++ii, ++jj;
      if (s[ii] != 0 && t[jj] != 0) {
        ++count, ++ii, ++jj;
        while (s[ii] != 0 && t[jj] != 0 && s[ii] == t[jj]) {
          ++count, ++ii, ++jj;
        }
      }
    }
  }
  return count;
}
