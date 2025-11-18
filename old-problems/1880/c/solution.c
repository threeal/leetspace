#include <stdbool.h>

static int convert(char* s);

bool isSumEqual(char* firstWord, char* secondWord, char* targetWord) {
  return convert(firstWord) + convert(secondWord) == convert(targetWord);
}

static int convert(char* s) {
  int num = 0;
  while (*s != 0) {
    num = num * 10 + *s - 'a';
    ++s;
  }
  return num;
}
