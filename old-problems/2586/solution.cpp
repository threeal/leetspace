#include <string>
#include <vector>

class Solution {
 public:
  int vowelStrings(std::vector<std::string>& words, int left, int right) {
    int count{0};
    for (int i{left}; i <= right; ++i) {
      if (isVowel(words[i].front()) && isVowel(words[i].back())) ++count;
    }
    return count;
  }

  static bool isVowel(char c) {
    switch (c) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        return true;
    }
    return false;
  }
};
