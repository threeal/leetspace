#include <stdint.h>
#include <string.h>

int wordCount(
    char** startWords, int startWordsSize,
    char** targetWords, int targetWordsSize) {
  uint8_t startMasksExist[(1 << 26) / 8] = {0};

  for (int i = startWordsSize - 1; i >= 0; --i) {
    uint32_t mask = 0;
    for (char* c = startWords[i]; *c != 0; ++c) {
      mask |= 1 << (*c - 'a');
    }
    startMasksExist[mask / 8] |= 1 << mask % 8;
  }

  int count = 0;
  for (int i = targetWordsSize - 1; i >= 0; --i) {
    uint32_t mask = 0;
    for (char* c = targetWords[i]; *c != 0; ++c) {
      mask |= 1 << (*c - 'a');
    }

    for (uint32_t i = 1 << 25; i > 0; i = i >> 1) {
      if (mask & i &&
          (startMasksExist[(mask ^ i) / 8] >> (mask ^ i) % 8 & 1) == 1) {
        ++count;
        break;
      }
    }
  }

  return count;
}
