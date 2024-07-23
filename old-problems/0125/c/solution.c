#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* s) {
  char* left = s;
  char* right = s + strlen(s) - 1;

  while (left < right) {
    while (left < right) {
      if (*left >= '0' && *left <= '9') break;
      if (*left >= 'A' && *left <= 'Z') break;
      if (*left >= 'a' && *left <= 'z') {
        *left += 'A' - 'a';
        break;
      }
      ++left;
    }

    while (left < right) {
      if (*right >= '0' && *right <= '9') break;
      if (*right >= 'A' && *right <= 'Z') break;
      if (*right >= 'a' && *right <= 'z') {
        *right += 'A' - 'a';
        break;
      }
      --right;
    }

    if (*left != *right) return false;

    ++left;
    --right;
  }

  return true;
}
