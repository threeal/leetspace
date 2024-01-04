int numberOfBeams(char** bank, int bankSize) {
  int lasers = 0;
  int prevBeams = 0;

  for (int i = 0; i < bankSize; ++i) {
    int beams = 0;

    char* c = bank[i];
    while (*c != 0) {
      if (*c == '1') ++beams;
      ++c;
    }

    if (beams > 0) {
      lasers += prevBeams * beams;
      prevBeams = beams;
    }
  }

  return lasers;
}
