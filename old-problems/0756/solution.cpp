#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  bool pyramidTransition(
      std::string bottom, std::vector<std::string>& allowed) {
    std::unordered_map<std::uint16_t, std::vector<char>> patterns{};
    for (const auto& pattern : allowed) {
      patterns[pattern[0] << 8 | pattern[1]].push_back(pattern[2]);
    }

    std::string top(bottom.size() - 1, ' ');
    return isPyramid(patterns, bottom, top, 0);
  }

 private:
  bool isPyramid(
      const std::unordered_map<std::uint16_t, std::vector<char>>& patterns,
      const std::string& bottom, std::string& top, std::size_t i) {
    if (i == top.size()) {
      if (i == 1) return true;

      std::string nextTop(top.size() - 1, ' ');
      return isPyramid(patterns, top, nextTop, 0);
    }

    const auto it = patterns.find(bottom[i] << 8 | bottom[i + 1]);
    if (it != patterns.end()) {
      for (char c : it->second) {
        top[i] = c;
        if (isPyramid(patterns, bottom, top, i + 1)) return true;
      }
    }

    return false;
  }
};
