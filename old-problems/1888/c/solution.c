int minFlips(char* s) {
  int i = 0, zeroDiff = 0, oneDiff = 0;
  while (s[i] != 0) {
    if (s[i] == '0') {
      ++oneDiff;
    } else {
      ++zeroDiff;
    }

    if (s[++i] == 0) break;

    if (s[i] == '1') {
      ++oneDiff;
    } else {
      ++zeroDiff;
    }

    ++i;
  }

  int minDiff = zeroDiff < oneDiff ? zeroDiff : oneDiff;
  if (i % 2 != 0) {
    for (--i; i > 0; --i) {
      const int temp = zeroDiff;
      zeroDiff = oneDiff;
      oneDiff = temp;
      if (s[i] == '1') {
        ++zeroDiff;
        --oneDiff;
        if (oneDiff < minDiff) minDiff = oneDiff;
      } else {
        --zeroDiff;
        ++oneDiff;
        if (zeroDiff < minDiff) minDiff = zeroDiff;
      }
    }
  }

  return minDiff;
}
