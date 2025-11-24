int countPrefixes(char** words, int wordsSize, char* s) {
  int count = 0;
  for (int i = 0; i < wordsSize; ++i) {
    int j = 0;
    while (words[i][j] != 0 && words[i][j] == s[j]) ++j;
    if (words[i][j] == 0) ++count;
  }
  return count;
}
