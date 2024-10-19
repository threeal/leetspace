#include <stdbool.h>
#include <string.h>

bool areSentencesSimilar(char* sentence1, char* sentence2) {
  int len1 = strlen(sentence1);
  int len2 = strlen(sentence2);
  if (len1 < len2) {
    char* tempSentence = sentence1;
    sentence1 = sentence2;
    sentence2 = tempSentence;

    const int tempLen = len1;
    len1 = len2;
    len2 = tempLen;
  }

  int prevSpace = -1;
  for (int i = 0; i < len2; ++i) {
    if (sentence1[i] != sentence2[i]) {
      goto backward;
    } else if (sentence2[i] == ' ') {
      prevSpace = i;
    }
  }

  if (len1 == len2) return true;
  if (sentence1[len2] == ' ') return true;

backward:;
  int nextSpace = len2;
  int j1 = len1 - 1;
  int j2 = len2 - 1;
  while (j2 >= 0) {
    if (sentence1[j1] != sentence2[j2]) return false;
    if (sentence2[j2] == ' ') {
      nextSpace = j2;
      if (nextSpace == prevSpace) return true;
    }
    --j1;
    --j2;
  }
  return j1 < 0 || sentence1[j1] == ' ';
}
