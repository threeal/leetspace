int maxDepth(char* s) {
  int maxCount = 0;
  int count = 0;

  while (*s != 0) {
    switch (*s) {
      case '(':
        ++count;
        if (count > maxCount) maxCount = count;
        break;

      case ')':
        --count;
        break;
    }
    ++s;
  }

  return maxCount;
}
