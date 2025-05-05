#include <string>

class Solution {
 public:
  std::string decodeMessage(std::string key, std::string message) {
    char map[26]{0};

    char val{'a'};
    for (const char c : key) {
      if (c != ' ' && map[c - 'a'] == 0) {
        map[c - 'a'] = val++;
      }
    }

    for (char& c : message) {
      if (c != ' ') c = map[c - 'a'];
    }

    return message;
  }
};
