#include <algorithm>
#include <cstdint>
#include <functional>
#include <string>
#include <vector>

class Solution {
 public:
  int maxLength(std::vector<std::string>& arr) {
    std::vector<std::uint32_t> uniques(arr.size(), 0);
    for (std::size_t i = 0; i < arr.size(); ++i) {
      for (const auto c : arr[i]) {
        uniques[i] |= 1 << (c - 'a');
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
