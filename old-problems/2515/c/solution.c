#include <string.h>

int closestTarget(char** words, int wordsSize, char* target, int startIndex) {
  int minDistance = wordsSize;
  for (int i = 0; i < wordsSize; ++i) {
    if (strcmp(words[i], target) == 0) {
      const int a = (wordsSize + startIndex - i) % wordsSize;
      const int b = (wordsSize - startIndex + i) % wordsSize;
      const int distance = a < b ? a : b;
      if (distance < minDistance) minDistance = distance;
    }
  }
  return minDistance == wordsSize ? -1 : minDistance;
}
