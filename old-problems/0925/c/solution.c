#include <stdbool.h>

bool isLongPressedName(char* name, char* typed) {
  char prevTyped = 0;

  while (*name != 0) {
    while (*name != *typed && prevTyped == *typed) ++typed;
    if (*name != *typed) return false;
    prevTyped = *typed;
    ++name;
    ++typed;
  }
  while (prevTyped == *typed) ++typed;

  return *typed == 0;
}
