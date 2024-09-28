#include <string>
#include <vector>

class Solution {
 public:
  int countConsistentStrings(
      std::string allowed, std::vector<std::string>& words) {
    std::vector<bool> exists(26, false);
    for (const auto c : allowed) {
      exists[c - 'a'] = true;
    }

    int count{0};
    for (const auto& word : words) {
      ++count;
      for (const auto c : word) {
        if (!exists[c - 'a']) {
          --count;
          break;
        }
      }
    }

    return count;
  }
};
