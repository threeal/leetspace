// The problem can be solved by finding the left and right pointers of each character
// and then counting the unique characters between those pointers.

class Solution {
 public:
  int countPalindromicSubsequence(string s) {
    // Find the left and right pointers of each character.
    unordered_map<char, pair<size_t, size_t>> charsPos;
    for (size_t i = 0; i < s.size(); ++i) {
      const auto it = charsPos.find(s[i]);
      if (it == charsPos.end())
        charsPos[s[i]] = {i, i};
      else
        it->second.second = i;
    }

    // Count the number of unique characters between each pair of pointers.
    int count = 0;
    for (const auto& [c, pos] : charsPos) {
      unordered_set<char> chars;
      for (auto i = pos.first + 1; i < pos.second; ++i) {
        chars.insert(s[i]);
      }
      count += chars.size();
    }

    return count;
  }
};
