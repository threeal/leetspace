#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

int openLock(char** deadends, int deadendsSize, char* targetStr) {
  if (targetStr[0] == '0' && targetStr[1] == '0' && targetStr[2] == '0' && targetStr[3] == '0') return 0;

  bool seen[10000];
  for (int i = 0; i < 10000; ++i) {
    seen[i] = false;
  }

  for (int i = 0; i < deadendsSize; ++i) {
    seen[atoi(deadends[i])] = true;
  }

  if (seen[0]) return -1;

  int16_t queue[1500];
  int queueBegin = 0;
  int queueEnd = 1;
  queue[queueBegin] = 0;
  seen[0] = true;

  int steps = 1;
  int16_t target = atoi(targetStr);
  while (queueBegin != queueEnd) {
    for (int i = (queueBegin < queueEnd ? queueEnd : 1500 + queueEnd) - queueBegin; i > 0; --i) {
      for (int16_t exp = 1; exp <= 1000; exp *= 10) {
        int key = queue[queueBegin];
        key += (key / exp) % 10 == 9 ? -9 * exp : exp;
        if (key == target) return steps;
        if (!seen[key]) {
          queue[queueEnd] = key;
          if (++queueEnd == 1500) queueEnd = 0;
          seen[key] = true;
        }

        key = queue[queueBegin];
        key += (key / exp) % 10 == 0 ? 9 * exp : -exp;
        if (key == target) return steps;
        if (!seen[key]) {
          queue[queueEnd] = key;
          if (++queueEnd == 1500) queueEnd = 0;
          seen[key] = true;
        }
      }
      if (++queueBegin == 1500) queueBegin = 0;
    }
    ++steps;
  }

  return -1;
}
