#include <cstdint>
#include <string>
#include <vector>

class Solution {
 public:
  int wordCount(
      std::vector<std::string>& startWords,
      std::vector<std::string>& targetWords) {
    std::vector<bool> startMaskExist(1 << 26, false);
    for (const auto& word : startWords) {
      std::uint32_t mask{0};
      for (const auto c : word) {
        mask |= 1 << (c - 'a');
      }
      startMaskExist[mask] = true;
    }

    int count{0};
    for (const auto& word : targetWords) {
      std::uint32_t mask{0};
      for (const auto c : word) {
        mask |= 1 << (c - 'a');
      }

      for (std::uint32_t i = 1 << 25; i > 0; i = i >> 1) {
        if (mask & i && startMaskExist[mask ^ i]) {
          ++count;
          break;
        }
      }
    }

    return count;
  }
};
