#include <string>
#include <unordered_map>

class Solution {
 public:
  bool closeStrings(std::string word1, std::string word2) {
    std::unordered_map<char, int> word1Counts;
    for (const auto c : word1) {
      ++word1Counts[c];
    }

    std::unordered_map<char, int> word2Counts;
    for (const auto c : word2) {
      ++word2Counts[c];
    }

    std::unordered_map<int, int> unique_counts;
    for (const auto& [c, count] : word1Counts) {
      if (!word2Counts.contains(c)) return false;
      ++unique_counts[count];
    }
    for (const auto& [c, count] : word2Counts) {
      if (!word1Counts.contains(c)) return false;
      --unique_counts[count];
    }

    for (const auto& [count, val] : unique_counts) {
      if (val != 0) return false;
    }

    return true;
  }
};
