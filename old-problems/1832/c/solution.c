#include <stdbool.h>
#include <stdint.h>

bool checkIfPangram(char* sentence) {
  uint32_t flag = 0;
  for (char* c = sentence; *c != 0; ++c) {
    flag |= 1 << (*c - 'a');
  }
  return flag == 0x3FFFFFF;
}
