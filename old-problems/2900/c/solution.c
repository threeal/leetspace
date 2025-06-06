char** getLongestSubsequence(
    char** words, int wordsSize, int* groups, int groupsSize, int* returnSize) {
  (void)groupsSize;
  int n = 1;
  int group = groups[0];
  for (int i = 1; i < wordsSize; ++i) {
    if (groups[i] != group) {
      group = groups[i];
      words[n++] = words[i];
    }
  }
  *returnSize = n;
  return words;
}
