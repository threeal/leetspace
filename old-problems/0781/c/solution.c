int numRabbits(int* answers, int answersSize) {
  int freqs[1000] = {0};
  for (int i = 0; i < answersSize; ++i) ++freqs[answers[i]];

  int num = 0;
  for (int i = 0; i < 1000; ++i) {
    num += (i + 1) * ((freqs[i] + i) / (i + 1));
  }

  return num;
}
