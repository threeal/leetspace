int secondsToRemoveOccurrences(char* s) {
  while (*s == '1') ++s;

  int maxSeconds = 0;
  int zeros = 0;
  int consecutiveOnes = 0;
  while (*s != 0) {
    if (*s == '1') {
      if (zeros + consecutiveOnes >= maxSeconds) {
        maxSeconds = zeros + consecutiveOnes;
      }
      ++consecutiveOnes;
    } else {
      ++zeros;
      if (consecutiveOnes > 0) --consecutiveOnes;
    }
    ++s;
  }
  return maxSeconds;
}
