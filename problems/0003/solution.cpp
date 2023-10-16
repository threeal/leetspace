class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    return longest(s.c_str(), s.size());
  }

  int longest(const char* str, int n) {
    unordered_set<char> cs;
    int i = 0;
    while (i < n) {
      if (cs.contains(str[i])) break;
      cs.insert(str[i]);
      ++i;
    }
    if (n <= 1) return i;
    auto j = longest(str + 1, n - 1);

    return max(i, j);
  }
};
