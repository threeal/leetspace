// The problem can be solved by finding the left and right pointers of each character
// and then counting the unique characters between those pointers.

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

class Solution {
 public:
  int countPalindromicSubsequence(std::string s) {
    // Find the left and right pointers of each character.
    std::unordered_map<char, std::pair<std::size_t, std::size_t>> charsPos;
    for (std::size_t i = 0; i < s.size(); ++i) {
      const auto it = charsPos.find(s[i]);
      if (it == charsPos.end())
        charsPos[s[i]] = {i, i};
      else
        it->second.second = i;
    }

    // Count the number of unique characters between each pair of pointers.
    int count = 0;
    for (const auto& [c, pos] : charsPos) {
      std::unordered_set<char> chars;
      for (auto i = pos.first + 1; i < pos.second; ++i) {
        chars.insert(s[i]);
      }
      count += chars.size();
    }

    return count;
  }
};
