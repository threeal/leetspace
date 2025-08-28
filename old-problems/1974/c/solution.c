#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int minTimeToType(char* word) {
  int steps = MIN(word[0] - 'a', 26 - word[0] + 'a');
  int i = 1;
  while (word[i] != 0) {
    steps += word[i] >= word[i - 1]
        ? MIN(word[i] - word[i - 1], 26 - word[i] + word[i - 1])
        : MIN(word[i - 1] - word[i], 26 - word[i - 1] + word[i]);
    ++i;
  }
  return steps + i;
}
