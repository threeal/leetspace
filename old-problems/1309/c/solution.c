char* freqAlphabets(char* s) {
  char* push = s;
  char* c = s;
  while (*c != 0) {
    switch (*c) {
      case '1':
        if (c[1] >= '0' && c[2] == '#') {
          *push = 'j' + c[1] - '0';
          ++push;
          c += 3;
          continue;
        }
        break;

      case '2':
        if (c[1] >= '0' && c[2] == '#') {
          *push = 't' + c[1] - '0';
          ++push;
          c += 3;
          continue;
        }
        break;
    }

    *push = 'a' + *c - '1';
    ++push;
    ++c;
  }
  *push = 0;
  return s;
}
