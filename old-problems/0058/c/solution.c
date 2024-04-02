int lengthOfLastWord(char* s) {
  char* b = s;
  char* i = s;

  while (*i != 0) {
    if (*i != ' ') {
      b = i;
    }
    ++i;
  }

  char* a = b;
  while (a >= s) {
    if (*a == ' ') {
      break;
    }
    --a;
  }

  return b - a;
}
