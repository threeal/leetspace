int lengthOfLastWord(char* s) {
  int b = 0;
  int i = 0;

  while (s[i] != 0) {
    if (s[i] != ' ') {
      b = i;
    }
    ++i;
  }

  int a = b;
  while (a >= 0) {
    if (s[a] == ' ') {
      break;
    }
    --a;
  }

  return b - a;
}
