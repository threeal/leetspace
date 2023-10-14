int lengthOfLastWord(char* s) {
  int b = 0;
  int i = 0;

  while (s[i] != 0) {
    if (s[i] == ' ') {
    } else {
      b = i;
    }
    ++i;
  }

  int a = 0;
  i = b;

  while (i >= 0) {
    if (s[i] == ' ') {
      a = i;
      break;
    }
    --i;
  }

  return b - a;
}
