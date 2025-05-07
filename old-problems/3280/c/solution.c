#include <stdlib.h>
#include <string.h>

char* convertDateToBinary(char* date) {
  char* output = malloc(26 * sizeof(char));
  memset(output, '0', 25 * sizeof(char));

  int i = 0, j = 0, num = 0;
  while (date[i] != '-') {
    num = num * 10 + date[i] - '0';
    ++i;
  }

  int bit = 1 << 12;
  while ((num & bit) == 0) bit >>= 1;
  while (bit != 0) {
    if ((num & bit) != 0) ++output[j];
    bit >>= 1;
    ++j;
  }

  ++i;
  output[j++] = '-';

  num = 0;
  while (date[i] != '-') {
    num = num * 10 + date[i] - '0';
    ++i;
  }

  bit = 1 << 5;
  while ((num & bit) == 0) bit >>= 1;
  while (bit != 0) {
    if ((num & bit) != 0) ++output[j];
    bit >>= 1;
    ++j;
  }

  ++i;
  output[j++] = '-';

  num = 0;
  while (date[i] != 0) {
    num = num * 10 + date[i] - '0';
    ++i;
  }

  bit = 1 << 6;
  while ((num & bit) == 0) bit >>= 1;
  while (bit != 0) {
    if ((num & bit) != 0) ++output[j];
    bit >>= 1;
    ++j;
  }

  output[j] = 0;
  return output;
}
