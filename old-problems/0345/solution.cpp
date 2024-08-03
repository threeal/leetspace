#include <string>
#include <utility>

constexpr bool isVowel(char c) {
  switch (c) {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      return true;
  }
  return false;
}

class Solution {
 public:
  std::string reverseVowels(std::string s) {
    std::size_t right = s.size() - 1;
    while (right > 0 && !isVowel(s[right])) --right;

    std::size_t left = 0;
    while (left < right && !isVowel(s[left])) ++left;

    while (left < right) {
      std::swap(s[left], s[right]);

      --right;
      while (left < right && !isVowel(s[right])) --right;

      ++left;
      while (left < right && !isVowel(s[left])) ++left;
    }

    return s;
  }
};
