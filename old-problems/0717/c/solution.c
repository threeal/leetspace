#include <stdbool.h>

bool isOneBitCharacter(int* bits, int bitsSize) {
  return bits[bitsSize - 1] == 0;
}
