#include <string.h>

int appendCharacters(char* s, char* t) {
  while (*s != 0) {
    if (*s == *t) ++t;
    ++s;
  }
  return strlen(t);
}
