#include <stdio.h>
#include <stdlib.h>

struct score_rank_t {
  int score;
  char** rank;
};

int comp(const void* a, const void* b) {
  return ((struct score_rank_t*)b)->score - ((struct score_rank_t*)a)->score;
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
  *returnSize = scoreSize;
  char** ranks = malloc(scoreSize * sizeof(char*));

  struct score_rank_t* scoreRanks = malloc(scoreSize * sizeof(struct score_rank_t));
  for (int i = scoreSize - 1; i >= 0; --i) {
    scoreRanks[i].score = score[i];
    scoreRanks[i].rank = ranks + i;
  }

  qsort(scoreRanks, scoreSize, sizeof(struct score_rank_t), comp);
  if (scoreSize > 0) *scoreRanks[0].rank = "Gold Medal";
  if (scoreSize > 1) *scoreRanks[1].rank = "Silver Medal";
  if (scoreSize > 2) *scoreRanks[2].rank = "Bronze Medal";
  for (int i = 3; i < scoreSize; ++i) {
    char* buffer = malloc(7 * sizeof(char));
    sprintf(buffer, "%d", i + 1);
    *scoreRanks[i].rank = buffer;
  }

  free(scoreRanks);

  return ranks;
}
