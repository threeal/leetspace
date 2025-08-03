#include <string.h>

char* answerString(char* word, int numFriends) {
  if (numFriends == 1) return word;
  const int wordLen = strlen(word);
  const int maxSize = wordLen - numFriends + 1;
  int answerLen = maxSize;
  int answer = 0;
  for (int i = 1; i < wordLen; ++i) {
    const int len = wordLen - i <= maxSize ? wordLen - i : maxSize;
    const int minLen = len <= answerLen ? len : answerLen;
    if (strncmp(word + i, word + answer, minLen) > 0) {
      answerLen = len;
      answer = i;
    }
  }

  word[answer + answerLen] = 0;
  return word + answer;
}
