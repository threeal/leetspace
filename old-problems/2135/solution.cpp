#include <cstdint>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int wordCount(
      std::vector<std::string>& startWords,
      std::vector<std::string>& targetWords) {
    std::unordered_set<std::uint32_t> startMasks{};
    for (const auto& word : startWords) {
      std::uint32_t mask{0};
      for (const auto c : word) {
        mask |= 1 << (c - 'a');
      }
      startMasks.insert(mask);
    }

    int count{0};
    for (const auto& word : targetWords) {
      std::uint32_t mask{0};
      for (const auto c : word) {
        mask |= 1 << (c - 'a');
      }

      for (std::uint32_t i = 1 << 25; i > 0; i = i >> 1) {
        if (mask & i && startMasks.contains(mask ^ i)) {
          ++count;
          break;
        }
      }
    }

    return count;
  }
};
