int minLength(char* s) {
  int i = -1;
  for (char* c = s; *c != 0; ++c) {
    if (i >= 0 && ((s[i] == 'A' && *c == 'B') || (s[i] == 'C' && *c == 'D'))) {
      --i;
    } else {
      s[++i] = *c;
    }
  }
  return i + 1;
}
