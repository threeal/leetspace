static int countPossibilities(int n, int* freqs, int freqsSize);

int numTilePossibilities(char* tiles) {
  int freqs[26] = {0};
  for (char* c = tiles; *c != '\0'; ++c) ++freqs[*c - 'A'];

  int freqsSize = 0;
  for (int i = 0; i < 26; ++i) {
    if (freqs[i] > 0) freqs[freqsSize++] = freqs[i];
  }

  int count = 0;
  for (int n = 0; tiles[n] != '\0'; ++n) {
    count += countPossibilities(n, freqs, freqsSize);
  }

  return count;
}

static int countPossibilities(int n, int* freqs, int freqsSize) {
  int count = 0;
  if (n == 0) {
    for (int i = 0; i < freqsSize; ++i) {
      if (freqs[i] > 0) ++count;
    }
  } else {
    for (int i = 0; i < freqsSize; ++i) {
      if (freqs[i] == 0) continue;
      --freqs[i];
      count += countPossibilities(n - 1, freqs, freqsSize);
      ++freqs[i];
    }
  }
  return count;
}
