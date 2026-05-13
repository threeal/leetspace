int longestBalanced(char* s) {
  int n = 0;
  while (s[n] != 0) {
    s[n] -= 'a';
    ++n;
  }

  int maxLength = 0;
  for (int l = 0; l < n; ++l) {
    int freqs[26] = {0};
    int maxFreqs = 0, maxFreqsCount = 0, count = 0;
    for (int r = l; r < n; ++r) {
      ++freqs[s[r]];
      if (freqs[s[r]] == 1) ++count;
      if (freqs[s[r]] == maxFreqs) {
        ++maxFreqsCount;
      } else if (freqs[s[r]] > maxFreqs) {
        maxFreqs = freqs[s[r]];
        maxFreqsCount = 1;
      }

      if (maxFreqsCount == count && r + 1 - l > maxLength) {
        maxLength = r + 1 - l;
      }
    }
  }

  return maxLength;
}
