#include <stdbool.h>
#include <stdint.h>

int canBeTypedWords(char* text, char* brokenLetters) {
  uint32_t isBrokenLetters = 0;
  for (int i = 0; brokenLetters[i] != 0; ++i) {
    isBrokenLetters |= 1 << (brokenLetters[i] - 'a');
  }

  int count = 0;
  bool isBroken = false;
  for (int i = 0; text[i] != 0; ++i) {
    if (text[i] == ' ') {
      if (!isBroken) ++count;
      isBroken = false;
    } else if (!isBroken && (isBrokenLetters & 1 << (text[i] - 'a')) != 0) {
      isBroken = true;
    }
  }

  return isBroken ? count : count + 1;
}
