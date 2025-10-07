#include <string>

class Solution {
 public:
  bool doesAliceWin(std::string s) {
    for (const char c : s) {
      switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
          return true;
      }
    }
    return false;
  }
};
