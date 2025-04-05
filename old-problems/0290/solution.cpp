#include <string>
#include <string_view>
#include <unordered_set>

class Solution {
 public:
  bool wordPattern(std::string pattern, std::string s) {
    std::string_view sentences(s);
    std::string_view words[26]{};
    std::unordered_set<std::string_view> exists{};

    std::size_t i{0}, r{0};
    while (i < pattern.size() && r < sentences.size()) {
      const std::size_t l{r};
      while (r < sentences.size() && sentences[r] != ' ') ++r;

      const auto word = sentences.substr(l, r - l);
      if (words[pattern[i] - 'a'].empty()) {
        if (exists.contains(word)) return false;
        words[pattern[i] - 'a'] = word;
        exists.insert(word);
      } else if (word != words[pattern[i] - 'a']) {
        return false;
      }

      ++i, ++r;
    }

    return i == pattern.size() && r == sentences.size() + 1;
  }
};
