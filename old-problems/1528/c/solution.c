#include <stdlib.h>

char* restoreString(char* s, int* indices, int indicesSize) {
  char* out = malloc((indicesSize + 1) * sizeof(char));
  for (int i = 0; i < indicesSize; ++i) {
    out[indices[i]] = s[i];
  }
  out[indicesSize] = 0;
  return out;
}
