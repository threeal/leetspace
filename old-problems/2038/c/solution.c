bool winnerOfGame(char* colors) {
  int a = 0;
  int b = 0;

  int start = 0;
  int i = 0;
  while (colors[i] != 0) {
    if (colors[i] != colors[start]) {
      if (i - start > 2) {
        if (colors[start] == 'A') {
          a += i - start - 2;
        } else {
          b += i - start - 2;
        }
      }
      start = i;
    }
    ++i;
  }

  if (i - start > 2) {
    if (colors[start] == 'A') {
      a += i - start - 2;
    } else {
      b += i - start - 2;
    }
  }

  return a > b;
}
