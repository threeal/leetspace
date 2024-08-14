#include <stdbool.h>

bool isCircularSentence(char* sentence) {
  int i = 0;
  while (sentence[i] != 0) {
    if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) {
      return false;
    }
    ++i;
  }
  return sentence[0] == sentence[i - 1];
}
