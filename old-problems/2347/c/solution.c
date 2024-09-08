char* bestHand(int* ranks, int ranksSize, char* suits, int suitsSize) {
  (void)suitsSize;
  for (int i = 4; i > 0; --i) {
    if (suits[i] != suits[0]) {
      int ones = 0, twos = 0;
      for (int j = 0; j < ranksSize; ++j) {
        if ((ones & (1 << ranks[j])) > 0) {
          if ((twos & (1 << ranks[j])) > 0) {
            return "Three of a Kind";
          } else {
            twos |= 1 << ranks[j];
          }
        } else {
          ones |= 1 << ranks[j];
        }
      }
      return twos > 0 ? "Pair" : "High Card";
    }
  }
  return "Flush";
}
