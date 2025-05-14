int mostWordsFound(char** sentences, int sentencesSize) {
  int maxSpaces = 0;
  for (int i = 0; i < sentencesSize; ++i) {
    int spaces = 0;
    for (int j = 0; sentences[i][j] != 0; ++j) {
      if (sentences[i][j] == ' ') ++spaces;
    }
    if (spaces > maxSpaces) maxSpaces = spaces;
  }
  return 1 + maxSpaces;
}
