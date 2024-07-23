#include <stdbool.h>
#include <string.h>

bool checkValidPalindromeWithDelete(char* left, char* right);
bool checkValidPalindrome(char* left, char* right);

bool validPalindrome(char* s) {
  return checkValidPalindromeWithDelete(s, s + strlen(s) - 1);
}

bool checkValidPalindromeWithDelete(char* left, char* right) {
  if (left >= right) return true;
  if (checkValidPalindrome(left + 1, right)) return true;
  if (checkValidPalindrome(left, right - 1)) return true;
  if (*left != *right) return false;
  return checkValidPalindromeWithDelete(left + 1, right - 1);
}

bool checkValidPalindrome(char* left, char* right) {
  while (left < right) {
    if (*left != *right) return false;
    ++left;
    --right;
  }
  return true;
}
