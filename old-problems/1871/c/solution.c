#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool canReach(char* s, int minJump, int maxJump) {
  const int sLen = strlen(s);

  if (s[sLen - 1] == '1') return false;

  int* jumps = malloc(sLen * sizeof(int));
  int front = 0, back = 0, laterBack = 0;
  jumps[laterBack++] = 0;

  for (int i = 1; i < sLen; ++i) {
    while (back < laterBack && jumps[back] + minJump <= i) ++back;
    while (front < back && jumps[front] + maxJump < i) ++front;

    if (front == back) {
      if (back == laterBack) {
        free(jumps);
        return false;
      }
    } else {
      if (s[i] == '0') jumps[laterBack++] = i;
    }
  }

  free(jumps);
  return front < back;
}
