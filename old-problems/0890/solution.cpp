#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> findAndReplacePattern(
      std::vector<std::string>& words, std::string pattern) {
    std::vector<char> charIds(26, 0);
    char charId{0};

    for (std::size_t i{0}; i < pattern.size(); ++i) {
      if (charIds[pattern[i] - 'a'] == 0) {
        charIds[pattern[i] - 'a'] = ++charId;
      }
      pattern[i] = charIds[pattern[i] - 'a'];
    }

    std::size_t n{0};
    for (std::size_t i{0}; i < words.size(); ++i) {
      std::string word{words[i]};

      charIds.assign(26, 0);
      charId = 0;

      bool valid{true};
      for (std::size_t j{0}; j < pattern.size(); ++j) {
        if (charIds[word[j] - 'a'] == 0) {
          charIds[word[j] - 'a'] = ++charId;
        }

        if (charIds[word[j] - 'a'] != pattern[j]) {
          valid = false;
          break;
        }
      }

      if (valid) words[n++] = words[i];
    }

    words.resize(n);
    return words;
  }
};
