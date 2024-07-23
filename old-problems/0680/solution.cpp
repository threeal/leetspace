#include <string>

class Solution {
 public:
  bool validPalindrome(std::string s) {
    return validPalindromeWithDelete(s.data(), s.data() + s.size() - 1);
  }

  bool validPalindromeWithDelete(char* left, char* right) {
    if (left >= right) return true;
    if (validPalindrome(left + 1, right)) return true;
    if (validPalindrome(left, right - 1)) return true;
    if (*left != *right) return false;
    return validPalindromeWithDelete(left + 1, right - 1);
  }

  bool validPalindrome(char* left, char* right) {
    while (left < right) {
      if (*left != *right) return false;
      ++left;
      --right;
    }
    return true;
  }
};
