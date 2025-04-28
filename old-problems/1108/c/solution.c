#include <stdlib.h>
#include <string.h>

char* defangIPaddr(char* address) {
  int addressLen = strlen(address);
  char* output = malloc((addressLen + 7) * sizeof(char));

  for (int i = 0, j = 0; i < addressLen; ++i, ++j) {
    if (address[i] == '.') {
      output[j] = '[';
      output[++j] = '.';
      output[++j] = ']';
    } else {
      output[j] = address[i];
    }
  }

  output[addressLen + 6] = 0;
  return output;
}
