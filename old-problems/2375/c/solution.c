#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool explore(char* output, char* pattern, bool* exists);

char* smallestNumber(char* pattern) {
  const int patternLen = strlen(pattern);

  char* output = malloc((patternLen + 2) * sizeof(char));
  output[patternLen + 1] = '\0';

  bool exists[9] = {false};
  for (char c = '1'; c <= '9'; ++c) {
    exists[c - '1'] = true;
    output[0] = c;
    if (explore(output, pattern, exists)) break;
    exists[c - '1'] = false;
  }
  return output;
}

static bool explore(char* output, char* pattern, bool* exists) {
  if (*pattern == 0) return true;
  if (*pattern == 'I') {
    for (char c = output[0] + 1; c <= '9'; ++c) {
      if (!exists[c - '1']) {
        exists[c - '1'] = true;
        output[1] = c;
        if (explore(output + 1, pattern + 1, exists)) return true;
        exists[c - '1'] = false;
      }
    }
  } else {
    for (char c = '1'; c < output[0]; ++c) {
      if (!exists[c - '1']) {
        exists[c - '1'] = true;
        output[1] = c;
        if (explore(output + 1, pattern + 1, exists)) return true;
        exists[c - '1'] = false;
      }
    }
  }
  return false;
}
