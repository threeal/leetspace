#include <stdlib.h>
#include <string.h>

int rankSize = 0;
int* ranks[27];

int compare(const void* a, const void* b) {
  const int* aRank = ranks[*(char*)a - 'A'];
  const int* bRank = ranks[*(char*)b - 'A'];
  for (int i = 0; i < rankSize; ++i) {
    if (aRank[i] == bRank[i]) continue;
    return bRank[i] - aRank[i];
  }
  return *(char*)a - *(char*)b;
}

char* rankTeams(char** votes, int votesSize) {
  rankSize = strlen(votes[0]);
  for (int i = 26; i >= 0; --i) {
    ranks[i] = malloc(rankSize * sizeof(int));
    memset(ranks[i], 0, rankSize * sizeof(int));
  }

  for (int i = votesSize - 1; i >= 0; --i) {
    for (int j = rankSize - 1; j >= 0; --j) {
      ++ranks[votes[i][j] - 'A'][j];
    }
  }

  qsort(votes[0], rankSize, sizeof(char), compare);

  for (int i = 26; i >= 0; --i) {
    free(ranks[i]);
  }

  return votes[0];
}
