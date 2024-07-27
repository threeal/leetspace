#include <string.h>

int maxRepeating(char* sequence, char* word) {
  const int sequenceSize = strlen(sequence);
  const int wordSize = strlen(word);
  int maxRepeating = 0;
  for (int i = wordSize - 1; i >= 0; --i) {
    int repeating = 0;
    for (int j = sequenceSize - wordSize - i; j >= 0; j -= wordSize) {
      for (int k = wordSize - 1; k >= 0; --k) {
        if (sequence[j + k] != word[k]) {
          repeating = -1;
          break;
        }
      }
      if (++repeating > 0) {
        if (maxRepeating < repeating) maxRepeating = repeating;
      }
    }
  }
  return maxRepeating;
}
