#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char** findAndReplacePattern(
    char** words, int wordsSize, char* pattern, int* returnSize) {
  char charIds[26];
  for (int i = 0; i < 26; ++i) charIds[i] = 0;

  char charId = 0;

  int patternSize = 0;
  while (pattern[patternSize] != 0) {
    if (charIds[pattern[patternSize] - 'a'] == 0) {
      charIds[pattern[patternSize] - 'a'] = ++charId;
    }
    pattern[patternSize] = charIds[pattern[patternSize] - 'a'];
    ++patternSize;
  }

  int n = 0;
  char* word = malloc(patternSize * sizeof(char));
  for (int i = 0; i < wordsSize; ++i) {
    memcpy(word, words[i], patternSize * sizeof(char));

    for (int i = 0; i < 26; ++i) charIds[i] = 0;
    charId = 0;

    bool valid = true;
    for (int j = 0; j < patternSize; ++j) {
      if (charIds[word[j] - 'a'] == 0) {
        charIds[word[j] - 'a'] = ++charId;
      }

      if (charIds[word[j] - 'a'] != pattern[j]) {
        valid = false;
        break;
      }
    }

    if (valid) words[n++] = words[i];
  }

  free(word);

  *returnSize = n;
  return words;
}
