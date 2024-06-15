#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char** commonChars(char** words, int wordsSize, int* returnSize) {
  int8_t allCounts[26];
  memset(allCounts, CHAR_MAX, 26 * sizeof(int8_t));

  int8_t counts[26];

  while (--wordsSize >= 0) {
    memset(counts, 0, 26 * sizeof(int8_t));
    for (char* c = words[wordsSize]; *c != 0; ++c) {
      ++counts[*c - 'a'];
    }

    for (int8_t i = 25; i >= 0; --i) {
      if (allCounts[i] > counts[i]) allCounts[i] = counts[i];
    }
  }

  *returnSize = 0;
  for (int8_t i = 25; i >= 0; --i) *returnSize += allCounts[i];

  char** chars = malloc((*returnSize) * sizeof(char*));
  for (int i = (*returnSize) - 1; i >= 0; --i) {
    chars[i] = malloc(2 * sizeof(char));
  }

  char** it = chars + (*returnSize) - 1;
  for (int8_t i = 25; i >= 0; --i) {
    while (--allCounts[i] >= 0) {
      (*it)[0] = 'a' + i;
      (*it)[1] = 0;
      --it;
    }
  }

  return chars;
}
