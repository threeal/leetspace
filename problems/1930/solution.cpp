class Solution {
 public:
  int countPalindromicSubsequence(string s) {
    unordered_map<char, size_t> charsLeft;
    unordered_map<char, size_t> charsRight;
    for (size_t i = 0; i < s.size(); ++i) {
      if (!charsLeft.contains(s[i])) charsLeft[s[i]] = i;
      charsRight[s[i]] = i;
    }

    int count = 0;
    for (const auto [c, left] : charsLeft) {
      if (!charsRight.contains(c)) continue;
      auto right = charsRight[c];

      unordered_set<char> chars;
      for (auto i = left + 1; i < right; ++i) {
        chars.insert(s[i]);
      }
      count += chars.size();
    }

    return count;
  }
};
