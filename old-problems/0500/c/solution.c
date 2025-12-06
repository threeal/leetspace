static char rowOf(char c);

char** findWords(char** words, int wordsSize, int* returnSize) {
  int n = 0;
  for (int i = 0; i < wordsSize; ++i) {
    const int row = rowOf(words[i][0]);

    int j = 1;
    while (words[i][j] != 0) {
      if (rowOf(words[i][j]) != row) break;
      ++j;
    }

    if (words[i][j] == 0) {
      words[n++] = words[i];
    }
  }

  *returnSize = n;
  return words;
}

static char rowOf(char c) {
  switch (c < 'a' ? c + 'a' - 'A' : c) {
    case 'q':
    case 'w':
    case 'e':
    case 'r':
    case 't':
    case 'y':
    case 'u':
    case 'i':
    case 'o':
    case 'p':
      return 1;

    case 'a':
    case 's':
    case 'd':
    case 'f':
    case 'g':
    case 'h':
    case 'j':
    case 'k':
    case 'l':
      return 2;

    case 'z':
    case 'x':
    case 'c':
    case 'v':
    case 'b':
    case 'n':
    case 'm':
      return 3;
  }

  return 0;
}
