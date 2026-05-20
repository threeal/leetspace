#include <string.h>

char** twoEditWords(
    char** queries, int queriesSize, char** dictionary, int dictionarySize,
    int* returnSize) {
  int n = 0;
  for (int i = 0; i < queriesSize; ++i) {
    const int queryLen = strlen(queries[i]);
    for (int j = 0; j < dictionarySize; ++j) {
      int diff = 0;
      for (int k = 0; k < queryLen; ++k) {
        if (queries[i][k] != dictionary[j][k]) {
          if (++diff > 2) break;
        }
      }

      if (diff <= 2) {
        queries[n++] = queries[i];
        break;
      }
    }
  }

  *returnSize = n;
  return queries;
}
