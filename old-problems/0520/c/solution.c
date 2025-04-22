#include <stdbool.h>

bool detectCapitalUse(char* word) {
  if (*word >= 'a') {
    ++word;
    while (*word >= 'a') ++word;
    return *word == 0;
  } else {
    ++word;
    if (*word >= 'a') {
      ++word;
      while (*word >= 'a') ++word;
      return *word == 0;
    } else if (*word >= 'A') {
      ++word;
      while (*word >= 'A' && *word <= 'Z') ++word;
      return *word == 0;
    }
  }
  return true;
}
