#include <stdlib.h>
#include <string.h>

int numWays(char** words, int wordsSize, char* target) {
  int wordLen = strlen(words[0]);
  int targetLen = strlen(target);
  if (wordLen < targetLen) return 0;

  int* freqs = malloc(26 * wordLen * sizeof(int));
  memset(freqs, 0, 26 * wordLen * sizeof(int));

  for (int i = 0; i < wordsSize; ++i) {
    for (int j = 0; j < wordLen; ++j) {
      ++freqs[j * 26 + words[i][j] - 'a'];
    }
  }

  int waysSize = wordLen + 1 - targetLen;
  long long* prevWays = malloc(waysSize * sizeof(long long));
  long long* ways = malloc(waysSize * sizeof(long long));
  for (int i = 0; i < waysSize; ++i) ways[i] = 1;

  for (int i = 0; i < targetLen; ++i) {
    long long* temp = prevWays;
    prevWays = ways;
    ways = temp;

    const int way = freqs[i * 26 + target[i] - 'a'];
    ways[0] = (way * prevWays[0]) % 1000000007;

    for (int j = 1; j < waysSize; ++j) {
      const int way = freqs[(i + j) * 26 + target[i] - 'a'];
      ways[j] = (ways[j - 1] + way * prevWays[j]) % 1000000007;
    }
  }

  return ways[waysSize - 1];
}
