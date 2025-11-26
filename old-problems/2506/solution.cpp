#include <cstdint>
#include <string>
#include <vector>

class Solution {
 public:
  int similarPairs(std::vector<std::string>& words) {
    std::vector<std::uint32_t> masks(words.size());
    for (std::size_t i{0}; i < words.size(); ++i) {
      std::uint32_t mask{0};
      for (const char c : words[i]) {
        mask |= 1 << (c - 'a');
      }
      masks[i] = mask;
    }

    std::sort(masks.begin(), masks.end());

    std::size_t l{0}, pairs{0};
    for (std::size_t r{1}; r < masks.size(); ++r) {
      if (masks[l] != masks[r]) {
        pairs += (r - l) * (r - l - 1) / 2;
        l = r;
      }
    }

    return pairs + (masks.size() - l) * (masks.size() - l - 1) / 2;
  }
};
