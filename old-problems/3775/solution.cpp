#include <algorithm>
#include <string>

class Solution {
 public:
  std::string reverseWords(std::string s) {
    std::size_t i{0};
    const int firstVowels{countVowels(s, i)};
    while (++i < s.size()) {
      const std::size_t l{i};
      const int vowels{countVowels(s, i)};
      if (vowels == firstVowels) {
        std::reverse(s.begin() + l, s.begin() + i);
      }
    }
    return s;
  }

 private:
  static int countVowels(const std::string& s, std::size_t& i) {
    int vowels{0};
    while (i < s.size() && s[i] != ' ') {
      switch (s[i]) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
          ++vowels;
      }
      ++i;
    }
    return vowels;
  }
};
