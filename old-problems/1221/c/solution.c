int balancedStringSplit(char* s) {
  int count = 0, balance = 0;
  for (char* c = s; *c != 0; ++c) {
    if (*c == 'L') {
      if (++balance == 0) ++count;
    } else {
      if (--balance == 0) ++count;
    }
  }
  return count;
}
