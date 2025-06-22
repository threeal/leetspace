int maximumNumberOfStringPairs(char** words, int wordsSize) {
  int count = 0;
  for (int j = 1; j < wordsSize; ++j) {
    for (int i = 0; i < j; ++i) {
      if (words[i][0] == words[j][1] && words[i][1] == words[j][0]) ++count;
    }
  }
  return count;
}
