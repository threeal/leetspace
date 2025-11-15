#include <stdbool.h>

bool isSumEqual(char* firstWord, char* secondWord, char* targetWord) {
  return *firstWord == *secondWord && *secondWord == *targetWord;
}
