#include <string>
#include <tuple>
#include <vector>

class Solution {
 public:
  std::string arrangeWords(std::string text) {
    text[0] += 'a' - 'A';

    std::vector<std::tuple<std::size_t, std::size_t>> wordRanges{};
    std::size_t l{0};
    for (std::size_t r{1}; r < text.size(); ++r) {
      if (text[r] == ' ') {
        wordRanges.push_back({l, r});
        l = r + 1;
      }
    }
    wordRanges.push_back({l, text.size()});

    std::sort(
        wordRanges.begin(), wordRanges.end(),
        [](const auto& a, const auto& b) {
          const auto [al, ar] = a;
          const auto [bl, br] = b;
          return ar - al != br - bl ? ar - al < br - bl : al < bl;
        });

    std::string out{};
    out.reserve(text.size());

    if (wordRanges.size() > 0) {
      const auto [l, r] = wordRanges[0];
      for (std::size_t i{l}; i < r; ++i) out += text[i];
      out[0] -= 'a' - 'A';

      for (std::size_t i{1}; i < wordRanges.size(); ++i) {
        out += ' ';

        const auto [l, r] = wordRanges[i];
        for (std::size_t j{l}; j < r; ++j) out += text[j];
      }
    }

    return out;
  }
};
