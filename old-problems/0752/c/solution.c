#include <stdint.h>
#include <string.h>

uint16_t to_int(char* str) {
  return (str[0] - '0') << 12 | (str[1] - '0') << 8 | (str[2] - '0') << 4 | (str[3] - '0');
}

int openLock(char** deadends, int deadendsSize, char* targetStr) {
  if (targetStr[0] == '0' && targetStr[1] == '0' && targetStr[2] == '0' && targetStr[3] == '0') return 0;

  uint8_t seen[8192];
  memset(seen, 0, 8192 * sizeof(uint8_t));
  for (int i = 0; i < deadendsSize; ++i) {
    int deadend = to_int(deadends[i]);
    seen[deadend / 8] |= 1 << deadend % 8;
  }

  if ((seen[0] & 1) == 1) return -1;

  uint16_t queue[1500];
  int queueBegin = 0;
  int queueEnd = 1;
  queue[queueBegin] = 0;
  seen[0] |= 1;

  int steps = 1;
  uint16_t target = to_int(targetStr);
  while (queueBegin != queueEnd) {
    for (int i = (queueBegin < queueEnd ? queueEnd : 1500 + queueEnd) - queueBegin; i > 0; --i) {
      for (int shift = 0; shift <= 12; shift += 4) {
        int key = queue[queueBegin];
        if ((key >> shift & 15) == 9) {
          key -= 9 << shift;
        } else {
          key += 1 << shift;
        }
        if (key == target) return steps;
        if ((seen[key / 8] >> key % 8 & 1) == 0) {
          queue[queueEnd] = key;
          if (++queueEnd == 1500) queueEnd = 0;
          seen[key / 8] |= 1 << key % 8;
        }

        key = queue[queueBegin];
        if ((key >> shift & 15) == 0) {
          key += 9 << shift;
        } else {
          key -= 1 << shift;
        }
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
