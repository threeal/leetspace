#include <string>

class Solution {
 public:
  bool halvesAreAlike(std::string s) {
    int l_vowels = 0;
    int r_vowels = 0;

    int l = 0;
    int r = s.size() - 1;
    while (l < r) {
      switch (s[l]) {
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
          ++l_vowels;
      }

      switch (s[r]) {
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
          ++r_vowels;
      }

      ++l;
      --r;
    }

    return l_vowels == r_vowels;
  }
};
