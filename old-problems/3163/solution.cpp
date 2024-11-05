#include <string>

class Solution {
 public:
  std::string compressedString(std::string word) {
    std::string out{};

    std::size_t i{0};
    while (i < word.size()) {
      const char c = word[i];

      std::size_t n{1};
      while (i + n < word.size() && word[i + n] == c) ++n;
      i += n;

      while (n > 0) {
        if (n > 9) {
          out += '9';
          n -= 9;
        } else {
          out += '0' + n;
          n = 0;
        }
        out += c;
      }
    }

    return out;
  }
};
