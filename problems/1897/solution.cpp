#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  bool makeEqual(std::vector<std::string>& words) {
    std::unordered_map<char, int> letter_counts;
    for (const auto& word : words) {
      for (const auto& letter : word) {
        ++letter_counts[letter];
      }
    }

    for (const auto [letter, count] : letter_counts) {
      if (count % words.size() != 0) return false;
    }

    return true;
  }
};
