#include <string.h>

int prefixCount(char** words, int wordsSize, char* pref) {
  int prefLen = strlen(pref);
  int count = 0;
  for (int i = 0; i < wordsSize; ++i) {
    if (strncmp(words[i], pref, prefLen) == 0) ++count;
  }
  return count;
}
