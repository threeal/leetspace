#include <algorithm>
#include <cstdint>
#include <functional>
#include <string>
#include <vector>

class Solution {
 public:
  int maxLength(std::vector<std::string>& arr) {
    std::vector<std::uint32_t> uniques;
    for (const auto& str : arr) {
      std::uint32_t unique = 0;
      for (const auto c : str) {
        std::uint32_t div = 1 << (c - 'a');
        if ((unique & div) != 0) {
          unique = 0;
          break;
        }
        unique |= div;
      }

      if (unique != 0) {
        uniques.push_back(unique);
      }
    }

    const std::function<int(std::size_t, std::uint32_t)> fn = [&](std::size_t i, std::uint32_t unique) {
      if (i == uniques.size()) {
        return __builtin_popcount(unique);
      }

      if ((unique & uniques[i]) == 0) {
        return std::max(
            fn(i + 1, unique | uniques[i]),
            fn(i + 1, unique));
      } else {
        return fn(i + 1, unique);
      }
    };

    return fn(0, 0);
  }
};
