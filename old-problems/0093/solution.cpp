#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> restoreIpAddresses(std::string s) {
    std::string out(s.size() + 3, ' ');
    std::vector<std::string> output{};

    for (std::size_t a{1}; isValidDigits(s, 0, a); ++a) {
      for (std::size_t i{0}; i < a; ++i) out[i] = s[i];
      out[a] = '.';

      for (std::size_t b{1}; isValidDigits(s, a, b); ++b) {
        const std::size_t ab{a + b};

        for (std::size_t i{0}; i < b; ++i) out[a + 1 + i] = s[a + i];
        out[ab + 1] = '.';

        for (std::size_t c{1}; ab + c < s.size(); ++c) {
          const std::size_t abc{ab + c};
          const std::size_t d{s.size() - abc};

          if (isValidDigits(s, ab, c) && isValidDigits(s, abc, d)) {
            for (std::size_t i{0}; i < c; ++i) out[ab + 2 + i] = s[ab + i];
            out[abc + 2] = '.';

            for (std::size_t i{0}; i < d; ++i) out[abc + 3 + i] = s[abc + i];

            output.push_back(out);
          }
        }
      }
    }

    return output;
  }

 private:
  static bool isValidDigits(
      const std::string& s, std::size_t i, std::size_t n) {
    if (i + n > s.size()) return false;
    switch (n) {
      case 1:
        return true;

      case 2:
        return s[i] != '0';

      case 3: {
        const char c0{s[i]}, c1{s[i + 1]}, c2{s[i + 2]};
        return c0 == '1' ||
            (c0 == '2' && (c1 < '5' || (c1 == '5' && c2 <= '5')));
      }
    }
    return false;
  }
};
