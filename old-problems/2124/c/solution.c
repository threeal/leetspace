#include <stdbool.h>

bool checkString(char* s) {
  while (*s == 'a') ++s;
  while (*s == 'b') ++s;
  return *s == 0;
}
