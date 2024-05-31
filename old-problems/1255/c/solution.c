#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int dfs(int8_t** wordsCount, int wordsCountSize, int index, int8_t* lettersCount, const int* score);

int maxScoreWords(char** words, int wordsSize, char* letters, int lettersSize, int* score, int scoreSize) {
  (void)scoreSize;

  int8_t** wordsCount = malloc(wordsSize * sizeof(int8_t*));
  for (int i = wordsSize - 1; i >= 0; --i) {
    wordsCount[i] = malloc(26 * sizeof(int8_t));
    memset(wordsCount[i], 0, 26 * sizeof(int8_t));

    for (char* letter = words[i]; *letter != 0; ++letter) {
      ++wordsCount[i][*letter - 'a'];
    }
  }

  int8_t lettersCount[26] = {0};
  for (int i = lettersSize - 1; i >= 0; --i) {
    ++lettersCount[letters[i] - 'a'];
  }

  const int max = dfs(wordsCount, wordsSize, 0, lettersCount, score);

  for (int i = wordsSize - 1; i >= 0; --i) free(wordsCount[i]);
  free(wordsCount);

  return max;
}

int dfs(int8_t** wordsCount, int wordsCountSize, int index, int8_t* lettersCount, const int* score) {
  if (index >= wordsCountSize) return 0;

  const int notPick = dfs(wordsCount, wordsCountSize, index + 1, lettersCount, score);

  for (int i = 25; i >= 0; --i) {
    if (wordsCount[index][i] > lettersCount[i]) return notPick;
  }

  int pick = 0;
  for (int i = 25; i >= 0; --i) {
    pick += score[i] * wordsCount[index][i];
    lettersCount[i] -= wordsCount[index][i];
  }

  pick += dfs(wordsCount, wordsCountSize, index + 1, lettersCount, score);

  for (int i = 25; i >= 0; --i) lettersCount[i] += wordsCount[index][i];

  return notPick > pick ? notPick : pick;
}
