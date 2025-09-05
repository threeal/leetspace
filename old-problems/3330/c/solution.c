int possibleStringCount(char* word) {
  int sum = 1;
  for (int i = 1; word[i] != 0; ++i) {
    if (word[i] == word[i - 1]) ++sum;
  }
  return sum;
}
