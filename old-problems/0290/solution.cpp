#include <string>
#include <string_view>

class Solution {
 public:
  bool wordPattern(std::string pattern, std::string s) {
    std::string_view sentences(s);
    std::string_view words[26]{};

    std::size_t i{0}, r{0};
    while (i < pattern.size() && r < sentences.size()) {
      const std::size_t l{r};
      while (r < sentences.size() && sentences[r] != ' ') ++r;

      const auto word = sentences.substr(l, r - l);
      if (words[pattern[i] - 'a'].empty()) {
        for (int j{pattern[i] - 'a' - 1}; j >= 0; --j) {
          if (words[j] == word) return false;
        }
        for (int j{pattern[i] - 'a' + 1}; j < 26; ++j) {
          if (words[j] == word) return false;
        }
        words[pattern[i] - 'a'] = word;
      } else if (word != words[pattern[i] - 'a']) {
        return false;
      }

      ++i, ++r;
    }

    return i == pattern.size() && r == sentences.size() + 1;
  }
};
