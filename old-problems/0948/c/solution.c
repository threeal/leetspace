#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int bagOfTokensScore(int* tokens, int tokensSize, int power) {
  int score = 0;

  qsort(tokens, tokensSize, sizeof(int), comp);

  int head = 0;
  int tail = tokensSize - 1;
  while (head <= tail) {
    const int prev_score = score;
    while (tokens[head] > power) {
      if (score == 0 || head == tail) return prev_score;
      power += tokens[tail];
      --score;
      --tail;
    }

    power -= tokens[head];
    ++score;
    ++head;
  }

  return score;
}
