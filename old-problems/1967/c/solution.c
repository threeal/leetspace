#include <string.h>

int numOfStrings(char** patterns, int patternsSize, char* word) {
  int count = 0;
  for (int i = 0; i < patternsSize; ++i) {
    if (strstr(word, patterns[i]) != NULL) ++count;
  }
  return count;
}
