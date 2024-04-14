char* makeGood(char* s) {
  int l = 0;
  for (int r = 1; s[r] != 0; ++r) {
    if (s[l] < s[r] ? s[l] + 32 == s[r] : s[l] == s[r] + 32) {
      if (l > 0) {
        --l;
      } else if (s[++r] != 0) {
        s[l] = s[r];
      } else {
        return "";
      }
    } else {
      s[++l] = s[r];
    }
  }

  s[l + 1] = 0;
  return s;
}
