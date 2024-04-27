#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int openLock(char** deadends, int deadendsSize, char* targetStr) {
  if (targetStr[0] == '0' && targetStr[1] == '0' && targetStr[2] == '0' && targetStr[3] == '0') return 0;

  uint8_t seen[1250];
  memset(seen, 0, 1250 * sizeof(uint8_t));
  for (int i = 0; i < deadendsSize; ++i) {
    int deadend = atoi(deadends[i]);
    seen[deadend / 8] |= 1 << deadend % 8;
  }

  if ((seen[0] & 1) == 1) return -1;

  int16_t queue[1500];
  int queueBegin = 0;
  int queueEnd = 1;
  queue[queueBegin] = 0;
  seen[0] |= 1;

  int steps = 1;
  int16_t target = atoi(targetStr);
  while (queueBegin != queueEnd) {
    for (int i = (queueBegin < queueEnd ? queueEnd : 1500 + queueEnd) - queueBegin; i > 0; --i) {
      for (int16_t exp = 1; exp <= 1000; exp *= 10) {
        int key = queue[queueBegin];
        key += (key / exp) % 10 == 9 ? -9 * exp : exp;
        if (key == target) return steps;
        if ((seen[key / 8] >> key % 8 & 1) == 0) {
          queue[queueEnd] = key;
          if (++queueEnd == 1500) queueEnd = 0;
          seen[key / 8] |= 1 << key % 8;
        }

        key = queue[queueBegin];
        key += (key / exp) % 10 == 0 ? 9 * exp : -exp;
        if (key == target) return steps;
        if ((seen[key / 8] >> key % 8 & 1) == 0) {
          queue[queueEnd] = key;
          if (++queueEnd == 1500) queueEnd = 0;
          seen[key / 8] |= 1 << key % 8;
        }
      }
      if (++queueBegin == 1500) queueBegin = 0;
    }
    ++steps;
  }

  return -1;
}
