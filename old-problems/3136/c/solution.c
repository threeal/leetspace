#include <stdbool.h>

bool isValid(char* word) {
  if (word[1] == 0 || word[2] == 0) return false;
  bool hasVowel = false, hasConsonant = false;
  for (char* c = word; *c != 0; ++c) {
    if (*c >= 'A' && *c <= 'Z') {
      switch (*c) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
          hasVowel = true;
          break;

        default:
          hasConsonant = true;
      }
    } else if (*c >= 'a' && *c <= 'z') {
      switch (*c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
          hasVowel = true;
          break;

        default:
          hasConsonant = true;
      }
    } else if (*c < '0' || *c > '9') {
      return false;
    }
  }
  return hasVowel && hasConsonant;
}
