#include <string>

class Solution {
 public:
  bool isPalindrome(std::string s) {
    std::size_t left{0};
    std::size_t right{s.size() - 1};

    while (left < right) {
      while (left < right) {
        if (s[left] >= '0' && s[left] <= '9') break;
        if (s[left] >= 'A' && s[left] <= 'Z') break;
        if (s[left] >= 'a' && s[left] <= 'z') {
          s[left] += 'A' - 'a';
          break;
        }
        ++left;
      }

      while (left < right) {
        if (s[right] >= '0' && s[right] <= '9') break;
        if (s[right] >= 'A' && s[right] <= 'Z') break;
        if (s[right] >= 'a' && s[right] <= 'z') {
          s[right] += 'A' - 'a';
          break;
        }
        --right;
      }

      if (s[left] != s[right]) return false;

      ++left;
      --right;
    }

    return true;
  }
};
