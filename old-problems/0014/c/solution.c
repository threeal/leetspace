char* longestCommonPrefix(char** strs, int strsSize) {
  for (int n = 0; strs[0][n] != 0; ++n) {
    for (int i = 1; i < strsSize; ++i) {
      if (strs[0][n] != strs[i][n]) {
        strs[0][n] = 0;
        return strs[0];
      }
    }
  }
  return strs[0];
}
