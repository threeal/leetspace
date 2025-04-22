int countSegments(char* s) {
  int count = 0, i = 0;
  while (s[i] != 0) {
    while (s[i] == ' ') ++i;
    if (s[i] != 0) {
      ++count;
      while (s[i] != 0 && s[i] != ' ') ++i;
    }
  }
  return count;
}
