#include <stdlib.h>
#include <string.h>

char* sortSentence(char* s) {
  char* words[9];
  int wordSizes[9] = {0};

  int l = 0, r = 0, wordsSize = 0;
  while (s[r] != 0) {
    if (s[r] == ' ') {
      words[s[r - 1] - '1'] = s + l;
      wordSizes[s[r - 1] - '1'] = r - l - 1;
      l = r + 1;
      ++wordsSize;
    }
    ++r;
  }

  words[s[r - 1] - '1'] = s + l;
  wordSizes[s[r - 1] - '1'] = r - l - 1;
  ++wordsSize;

  const int outputSize = r - wordsSize;
  char* output = malloc((outputSize + 1) * sizeof(int));

  for (int l = 0, i = 0; i < wordsSize; ++i) {
    memcpy(output + l, words[i], wordSizes[i] * sizeof(char));
    output[l + wordSizes[i]] = ' ';
    l += wordSizes[i] + 1;
  }

  output[outputSize] = 0;
  return output;
}
