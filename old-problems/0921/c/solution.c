int minAddToMakeValid(char* s) {
  int added = 0;
  int level = 0;
  while (*s != 0) {
    if (*s == '(') {
      ++level;
    } else {
      if (level == 0) {
        ++added;
      } else {
        --level;
      }
    }
    ++s;
  }
  return level + added;
}
